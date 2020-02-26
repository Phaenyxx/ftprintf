/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:05:50 by trifflet          #+#    #+#             */
/*   Updated: 2020/02/24 15:16:04 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	empty(t_data *data)
{
	int i;

	i = 0;
	while (i++ < 127)
		data->inputs.keyboard[i] = 0;
	data->inputs.time = get_time();
}

void	set_background(t_data *data)
{
	int i;

	data->window.background = create_image(data->window.width,\
		data->window.height, data);
	i = 0;
	while (i < data->window.height * data->window.width / 2)
	{
		data->window.background.data[i++] = data->sprites.ceiling;
	}
	while (i < data->window.height * data->window.width)
	{
		data->window.background.data[i++] = data->sprites.floor;
	}
}

void	startup(t_data *data)
{
	empty(data);
	if ((data->window.mlx_ptr = mlx_init()) == NULL)
		ft_exit(EXIT_FAILURE);
	set_background(data);
	if ((data->window.window = mlx_new_window(data->window.mlx_ptr,\
		data->window.width, data->window.height, "Cub3D")) == NULL)
		ft_exit(EXIT_FAILURE);
}
