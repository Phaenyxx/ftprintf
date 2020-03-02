/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:07:03 by trifflet          #+#    #+#             */
/*   Updated: 2020/03/02 15:16:49 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_pixel	find_wallcolor(int side)
{
	t_pixel color;

	color.red = (char)143;
	color.green = (char)188;
	color.blue = (char)187;
	color.alpha = 0;
	if (side == 1)
	{
		color.red = (char)136;
		color.green = (char)192;
		color.blue = (char)208;
	}
	if (side == 2)
	{
		color.red = (char)129;
		color.green = (char)161;
		color.blue = (char)193;
	}
	if (side == 3)
	{
		color.red = (char)94;
		color.green = (char)129;
		color.blue = (char)172;
	}
	return (color);
}

t_pixel	find_minicolor(int x, int y, t_data *data)
{
	t_pixel	color;

	color = data->sprites.ceiling;
	if (data->map.map[y][x] == 'P')
	{
		color.red = (char)191;
		color.green = (char)97;
		color.blue = (char)106;
		data->map.map[y][x] = '.';
	}
	if (data->map.map[y][x] == 'o')
	{
		color.red = (char)76;
		color.green = (char)86;
		color.blue = (char)106;
		data->map.map[y][x] = '.';
	}
	if (data->map.map[y][x] == '1')
	{
		color.red = (char)216;
		color.green = (char)222;
		color.blue = (char)233;
	}
	return (color);
}

void	minimap(t_data *data)
{
	t_pixel	c;
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->map.map[(int)data->geo.pos.y][(int)data->geo.pos.x] = 'P';
	while (y < data->map.height)
	{
		while (x < data->map.width)
		{
			c = find_minicolor(x, y, data);
			data->window.bg.data[(y * 2 * data->window.w) + (x * 2)] = c;
			data->window.bg.data[(y * 2 * data->window.w) + (x * 2) + 1] = c;
			data->window.bg.data[((y * 2 + 1) * data->window.w) +\
				(x * 2)] = c;
			data->window.bg.data[((y * 2 + 1) * data->window.w) +\
				(x * 2) + 1] = c;
			x++;
		}
		x = 0;
		y++;
	}
}
