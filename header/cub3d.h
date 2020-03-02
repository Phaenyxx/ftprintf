/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:53:51 by trifflet          #+#    #+#             */
/*   Updated: 2020/03/02 19:38:25 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>
# include "mlx.h"
# include "enum.h"
# include "get_next_line.h"
# include "printf.h"

# define ROT_SPEED .003
# define MOVE_SPEED .004
# define BLUR_DECAY 3
# define BLUR_STRENGTH 210
typedef long long int	t_timer;

typedef struct			s_pixel
{
	char				blue;
	char				green;
	char				red;
	char				alpha;
}						t_pixel;

typedef struct			s_inputs
{
	t_timer				time;
	char				keyboard[255];
	int					close;
}						t_inputs;

typedef struct			s_sprites
{
	void				*north;
	void				*south;
	void				*west;
	void				*east;
	t_pixel				ceiling;
	t_pixel				floor;
}						t_sprites;

typedef struct			s_map
{
	char				**map;
	int					width;
	int					height;
	int					validity;
}						t_map;

typedef struct			s_image
{
	void				*ptr;
	t_pixel				*data;
	int					bpp;
	int					line_size;
	int					endian;
}						t_image;

typedef struct			s_window
{
	void				*mlx_ptr;
	void				*window;
	t_image				bg;
	int					w;
	int					h;

}						t_window;

typedef struct			s_linefeed
{
	char				*line;
	struct s_linefeed	*next;
}						t_linefeed;

typedef struct			s_pos
{
	int				x;
	int				y;
}						t_pos;

typedef struct			s_vector
{
	double				x;
	double				y;
}						t_vector;

typedef struct			s_geo
{
	t_vector			pos;
	t_vector			dir_player;
	t_vector			plane;
}						t_geo;

typedef struct			s_data
{
	t_inputs			inputs;
	t_sprites			sprites;
	t_window			window;
	t_map				map;
	t_geo		geo;
}						t_data;

typedef struct			s_ray
{
	double				camera;
	t_vector			dir;
	t_pos				map;
	t_vector			delta;
	t_vector			side_dist;
	double				wall_dist;
	t_pos				step;
	int					hit;
	int					side;
	int					line_height;
	t_pos				draw;
}						t_ray;

void					startup(t_data *data);
int						get_infos(char *file, t_data *data);
int						get_map(char *line, int fd, t_data *data);
int						is_in(char c, char *set);
int						max (int a, int b);
char					*skip(char *str, int n);
void					find_player(int *x, int *y, t_data *data);
int						check_line(char *line, char *set);
int						check_line2(char *line, char *set);
int						check_sequence(char *line,\
							char *sequence, char *control);
int						check_map(t_data *data);
void					set_background(t_data *data, int creation);
void					minimap(t_data *data);
t_pixel					find_wallcolor(int side);
t_pixel					find_minicolor(int x, int y, t_data *data);
void					deltadist(t_vector *delta, t_vector dir);
long long int			get_time(void);
void					forward(t_data *data, t_timer t);
void					slide(t_data *data, t_timer t);
void					rotate(t_data *data, t_timer t);
void					hooker(t_data *data);
int						loop(t_data *data);
void					render(t_data *data);
int						get_next_line(int fd, char **line);
t_image					create_image(int w, int y, t_data *data);
int						ft_exit(int ret);

#endif
