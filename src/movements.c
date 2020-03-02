/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:03:52 by trifflet          #+#    #+#             */
/*   Updated: 2020/03/02 19:50:58 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void forward(t_data *data, t_timer t)
{
	double speed;

	speed = t * MOVE_SPEED;
	speed += (speed * .75 * data->inputs.keyboard[UP_ARROW]);
	if (data->map.map[(int)data->geo.pos.y][(int)(data->geo.pos.x + data->geo.dir_player.x * speed)] == '.')
	data->geo.pos.x += data->geo.dir_player.x * speed;
	if (data->map.map[(int)(data->geo.pos.y + data->geo.dir_player.y * speed)][(int)data->geo.pos.x] == '.')
	data->geo.pos.y += data->geo.dir_player.y * speed;
}

void slide(t_data *data, t_timer t)
{
	double speed;

	speed = t * MOVE_SPEED;
	speed += (speed * .75 * data->inputs.keyboard[UP_ARROW]);
	if (data->map.map[(int)data->geo.pos.y][(int)(data->geo.pos.x - data->geo.dir_player.y * speed)] == '.')
	data->geo.pos.x -= data->geo.dir_player.y * speed;
	if (data->map.map[(int)(data->geo.pos.y + data->geo.dir_player.x * speed)][(int)data->geo.pos.x] == '.')
	data->geo.pos.y += data->geo.dir_player.x * speed;
}

void rotate(t_data *data, t_timer t)
{
	t_vector old_dir;
	t_vector old_plane;
	double rotation;

	rotation = t * ROT_SPEED;
	rotation += (rotation * (-.25 + 1 * (!(data->inputs.keyboard[Q] || data->inputs.keyboard[E] ||\
		data->inputs.keyboard[W] || data->inputs.keyboard[S]))) * data->inputs.keyboard[UP_ARROW]);
	old_dir.x = data->geo.dir_player.x;
	data->geo.dir_player.x = (data->geo.dir_player.x * cos(-rotation)) - (data->geo.dir_player.y * sin(-rotation));
	data->geo.dir_player.y = old_dir.x * sin(-rotation) + data->geo.dir_player.y * cos(-rotation);
	old_plane.x = data->geo.plane.x;
	data->geo.plane.x = (data->geo.plane.x * cos(-rotation)) - (data->geo.plane.y * sin(-rotation));
	data->geo.plane.y = old_plane.x * sin(-rotation) + data->geo.plane.y * cos(-rotation);
}