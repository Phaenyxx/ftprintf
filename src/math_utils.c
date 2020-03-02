/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:54:34 by trifflet          #+#    #+#             */
/*   Updated: 2020/03/02 12:32:53 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	deltadist(t_vector *delta, t_vector dir)
{
	if (dir.y == 0)
		delta->x = 0;
	else if (dir.x == 0)
		delta->x = 1;
	else
		delta->x = 1 / dir.x > 0 ? 1 / dir.x : -(1 / dir.x);
	if (dir.x == 0)
		delta->y = 0;
	else if (dir.y == 0)
		delta->y = 1;
	else
		delta->y = 1 / dir.y > 0 ? 1 / dir.y : -(1 / dir.y);
}
