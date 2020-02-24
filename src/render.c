/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:23:07 by trifflet          #+#    #+#             */
/*   Updated: 2020/02/20 17:16:11 by trifflet         ###   ########lyon.fr   */
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

void	render(t_data *data)
{
	(void)data;
	mlx_put_image_to_window(data->window.mlx_ptr,\
		data->window.window, data->window.background.ptr, 0, 0);
}
