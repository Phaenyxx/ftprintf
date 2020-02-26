/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:51:44 by trifflet          #+#    #+#             */
/*   Updated: 2020/02/26 17:46:59 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int		is_out(int x, int y, t_map map)
{
	if (x == map.width || x == 0)
		return (1);
	if (y == map.height || y == 0)
		return (1);
	return (0);
}

void	check_cell(int x, int y, t_data *data)
{
	if (!data->map.validity)
		return ;
	if (is_out(x, y, data->map))
		data->map.validity = 0;
	else
		data->map.map[y][x]	= '.';
	if( x > 0 && data->map.map[y][x - 1] == '0')
		check_cell(x - 1, y, data);
	if( y > 0 && data->map.map[y - 1][x] == '0')
		check_cell(x, y - 1, data);
	if( x < data->map.width && data->map.map[y][x + 1] == '0')
		check_cell(x + 1, y, data);
	if( y < data->map.height && data->map.map[y + 1][x] == '0')
		check_cell(x, y + 1, data);
}

void	find_player(int *x, int *y, t_data *data)
{
	while (*y < data->map.height && !is_in(data->map.map[*y][*x], "NSWE"))
	{
		(*x)++;
		if (*x == data->map.width)
		{
			*x = 0;
			(*y)++;
		}
	}
	if (*y == data->map.height)
		data->map.validity = 0;
}

int		check_map(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	find_player(&x, &y, data);
	if (is_out(x, y, data->map))
		return (ERROR);
	if( x > 0 && data->map.map[y][x - 1] == '0')
		check_cell(x - 1, y, data);
	if( y > 0 && data->map.map[y - 1][x] == '0')
		check_cell(x, y - 1, data);
	if( x < data->map.width && data->map.map[y][x + 1] == '0')
		check_cell(x + 1, y, data);
	if( y < data->map.height && data->map.map[y + 1][x] == '0')
		check_cell(x, y + 1, data);
	if (data->map.validity)
		return (MAP_GET);
	return (ERROR);
}