/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:05:50 by trifflet          #+#    #+#             */
/*   Updated: 2020/03/02 15:01:13 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_image	create_image(int w, int y, t_data *data)
{
	t_image	img;

	img.ptr = mlx_new_image(data->window.mlx_ptr, w, y);
	img.data = (t_pixel *)mlx_get_data_addr(img.ptr,\
		&img.bpp, &img.line_size, &img.endian);
	return (img);
}

void	empty(t_data *data)
{
	int i;

	i = 0;
	while (i++ < 127)
		data->inputs.keyboard[i] = 0;
	data->inputs.time = get_time();
}

void	set_background(t_data *data, int creation)
{
	int i;

	if (creation)
		data->window.bg = create_image(data->window.w,\
			data->window.h, data);
	i = 0;
	while (i < data->window.h * data->window.w / 2)
		data->window.bg.data[i++] = data->sprites.ceiling;
	while (i < data->window.h * data->window.w)
		data->window.bg.data[i++] = data->sprites.floor;
}

void	get_orientation(t_data *data)
{
	char c;
	
	c = data->map.map[(int)data->geo.pos.y][(int)data->geo.pos.x];
	data->geo.dir_player.x = 0;
	data->geo.dir_player.y = 0;
	data->geo.plane.x = 0.66;
	data->geo.plane.y = 0;
	if (c == 'N')
		data->geo.dir_player.y = -1;
	if (c == 'S')
		data->geo.dir_player.y = 1;
	if (c == 'W')
	{
		data->geo.dir_player.x = -1;
		data->geo.plane.y = 0.66;
		data->geo.plane.x = 0;
	}
	if (c == 'E')
	{
		data->geo.dir_player.x = 1;
		data->geo.plane.y = 0.66;
		data->geo.plane.x = 0;
	}
	data->map.map[(int)data->geo.pos.y][(int)data->geo.pos.x] = '.';
}

void	startup(t_data *data)
{
	empty(data);
	if ((data->window.mlx_ptr = mlx_init()) == NULL)
		ft_exit(EXIT_FAILURE);
	set_background(data, 1);
	get_orientation(data);
	if ((data->window.window = mlx_new_window(data->window.mlx_ptr,\
		data->window.w, data->window.h, "Cub3D")) == NULL)
		ft_exit(EXIT_FAILURE);
}
