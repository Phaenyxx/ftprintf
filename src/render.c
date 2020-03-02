/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:23:07 by trifflet          #+#    #+#             */
/*   Updated: 2020/03/02 13:16:04 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	create_ray(t_ray *ray, t_data *data, int i)
{
	ray->camera = 2 * i / (double)(data->window.w) - 1;
	ray->dir.x = data->geo.dir_player.x + (data->geo.plane.x * ray->camera);
	ray->dir.y = data->geo.dir_player.y + (data->geo.plane.y * ray->camera);
	ray->map.x = data->geo.pos.x;
	ray->map.y = data->geo.pos.y;
	deltadist(&ray->delta, ray->dir);
	if (ray->dir.x < 0)
		ray->side_dist.x = (data->geo.pos.x - ray->map.x) * ray->delta.x;
	else
		ray->side_dist.x = (ray->map.x + 1.0 - data->geo.pos.x) * ray->delta.x;
	if (ray->dir.y < 0)
		ray->side_dist.y = (data->geo.pos.y - ray->map.y) * ray->delta.y;
	else
		ray->side_dist.y = (ray->map.y + 1.0 - data->geo.pos.y) * ray->delta.y;
	ray->step.x = ray->dir.x < 0 ? -1 : 1;
	ray->step.y = ray->dir.y < 0 ? -1 : 1;
	ray->hit = 0;
}

void	get_to_wall(t_ray *ray, t_data *data, int i)
{
	(void)i;
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta.x;
			ray->map.x += ray->step.x;
			ray->side = ray->step.x > 0 ? 0 : 2;
		}
		else
		{
			ray->side_dist.y += ray->delta.y;
			ray->map.y += ray->step.y;
			ray->side = ray->step.y > 0 ? 1 : 3;
		}
		if (data->map.map[ray->map.y][ray->map.x] == '.')
			data->map.map[ray->map.y][ray->map.x] = 'o';
		if (data->map.map[ray->map.y][ray->map.x] != '.' &&\
			data->map.map[ray->map.y][ray->map.x] != 'o')
		{
			ray->hit = 1;
		}
	}
}

void	calculate_line(t_ray *ray, t_data *data)
{
	ray->wall_dist = (ray->side % 2 == 0) ?\
		(ray->map.x - data->geo.pos.x + (1 - ray->step.x) / 2) / ray->dir.x :
		(ray->map.y - data->geo.pos.y + (1 - ray->step.y) / 2) / ray->dir.y;
	ray->line_height = (int)(data->window.h / ray->wall_dist);
	ray->draw.x = -(ray->line_height / 2) + (data->window.h / 2);
	ray->draw.x = (ray->draw.x < 0) ? 0 : ray->draw.x;
	ray->draw.y = (ray->line_height / 2) + (data->window.h / 2);
	ray->draw.y = (ray->draw.y >= data->window.h)\
			? data->window.h - 1 : ray->draw.y;
}

void	draw_line(t_ray ray, int i, t_data *data)
{
	int		x;
	t_pixel	color;

	color = find_wallcolor(ray.side);
	x = ray.draw.x;
	while (x <= ray.draw.y)
	{
		data->window.bg.data[x * data->window.w + i].red = color.red;
		data->window.bg.data[x * data->window.w + i].green = color.green;
		data->window.bg.data[x * data->window.w + i].blue = color.blue;
		x++;
	}
}

void	render(t_data *data)
{
	int		i;
	t_ray	ray;

	i = 0;
	set_background(data, 0);
	while (i < data->window.w)
	{
		create_ray(&ray, data, i);
		get_to_wall(&ray, data, i);
		calculate_line(&ray, data);
		draw_line(ray, i, data);
		i++;
	}
	minimap(data);
	mlx_put_image_to_window(data->window.mlx_ptr,\
		data->window.window, data->window.bg.ptr, 0, 0);
}
