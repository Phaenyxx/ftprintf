/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:53:48 by trifflet          #+#    #+#             */
/*   Updated: 2020/02/26 17:25:16 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int		ft_exit(int ret)
{
	exit(ret);
	return (0);
}

int		loop(t_data *data)
{
	t_timer actual;

	actual = get_time();
	if (actual - data->inputs.time < 16)
	{
		usleep(1000 * (actual - data->inputs.time));
		return (0);
	}
	data->inputs.time = actual;
	if (data->inputs.keyboard[ESCAPE])
		ft_exit(0);
	render(data);
	return (0);
}

int		main(void)
{
	t_data	data;

	get_infos("test.cub", &data);
	ft_printf("%s", data.map.validity ? "GG\n" : "bite\n");
	for (int f = 0; f < data.map.height; f++)
		printf("%s\n", data.map.map[f]);
	startup(&data);
	hooker(&data);
	mlx_loop(data.window.mlx_ptr);
	return (EXIT_SUCCESS);
}
