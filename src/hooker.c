/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:47:29 by trifflet          #+#    #+#             */
/*   Updated: 2020/02/18 17:25:16 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int		key_input_press(int keycode, t_data *data)
{
	data->inputs.keyboard[keycode] = 1;
	return (0);
}

int		key_input_release(int keycode, t_data *data)
{
	data->inputs.keyboard[keycode] = 0;
	return (0);
}

void	hooker(t_data *data)
{
	mlx_do_key_autorepeatoff(data->window.mlx_ptr);
	mlx_hook(data->window.window,\
		KEY_PRESS_CODE, 0, &key_input_press, data);
	mlx_hook(data->window.window,\
		KEY_RELEASE_CODE, 0, &key_input_release, data);
	mlx_hook(data->window.window, RED_BUTTON_CODE, 0, &ft_exit, 0);
	mlx_loop_hook(data->window.mlx_ptr, loop, data);
}
