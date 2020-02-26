/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:53:51 by trifflet          #+#    #+#             */
/*   Updated: 2020/02/26 18:18:54 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include "mlx.h"
# include "enum.h"
# include "get_next_line.h"
# include "printf.h"

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
	char				keyboard[128];
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
	t_image				background;
	t_image				rendered;
	int					width;
	int					height;

}						t_window;

typedef struct			s_linefeed
{
	char				*line;
	struct s_linefeed	*next;
}						t_linefeed;

typedef struct			s_data
{
	t_inputs			inputs;
	t_sprites			sprites;
	t_window			window;
	t_map				map;
}						t_data;

void					startup(t_data *data);
int						get_infos(char *file, t_data *data);
int						get_map(char *line, int fd, t_data *data);
int						is_in(char c, char *set);
int						max (int a, int b);
char					*skip(char *str, int n);
int						check_line(char *line);
int						check_sequence(char *line,\
							char *sequence, char *control);
int						check_map(t_data *data);
long long int			get_time(void);
void					hooker(t_data *data);
int						loop(t_data *data);
void					render(t_data *data);
int						get_next_line(int fd, char **line);
t_image					create_image(int w, int y, t_data *data);
int						ft_exit(int ret);

#endif
