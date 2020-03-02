/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:53:48 by trifflet          #+#    #+#             */
/*   Updated: 2020/03/02 19:45:45 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int		ft_exit(int ret)
{
	exit(ret);
	return (0);
}

void handle_inputs(t_data *data, int time)
{
	if (data->inputs.keyboard[Q])
		slide(data, -time);
	if (data->inputs.keyboard[E])
		slide(data, time);
	if (data->inputs.keyboard[W])
		forward(data, time);
	if (data->inputs.keyboard[S])
		forward(data, -time);
	if (data->inputs.keyboard[A])
		rotate(data, time);
	if (data->inputs.keyboard[D])
		rotate(data, -time);
	if (data->inputs.keyboard[Q] || data->inputs.keyboard[E] ||\
		data->inputs.keyboard[W] || data->inputs.keyboard[S] ||\
		data->inputs.keyboard[A] || data->inputs.keyboard[D])
	{
		data->sprites.ceiling.alpha = (char)(BLUR_STRENGTH * data->inputs.keyboard[UP_ARROW]);
		data->sprites.floor.alpha = (char)(BLUR_STRENGTH * data->inputs.keyboard[UP_ARROW]);
	}
	else
	{
		data->sprites.ceiling.alpha -= BLUR_DECAY;
		data->sprites.floor.alpha -= BLUR_DECAY;
	}
}

int		loop(t_data *data)
{
	t_timer new_time;

	new_time = get_time();
	new_time -= data->inputs.time;
	if (new_time < 16)
	{
		usleep(1000 * (new_time));
		return (0);
	}
	handle_inputs(data, new_time);
	data->inputs.time += new_time;
	if (data->inputs.keyboard[ESCAPE])
		ft_exit(0);
	render(data);
	return (0);
}

int		main(void)
{
	int error;
	t_data	data;

	if(((error = get_infos("test.cub", &data)) & 1023) != RESOLUTION + FLOOR_COLOR + CEILING_COLOR + MAP_GET)
	{
		ft_printf("Error\n");
		if (!(error & RESOLUTION))
			ft_printf("Resolution isn't well formatted\n");
		return (0);
	}
	startup(&data);
	hooker(&data);
	mlx_loop(data.window.mlx_ptr);

	return (EXIT_SUCCESS);
}
