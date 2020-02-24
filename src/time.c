/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:21:22 by trifflet          #+#    #+#             */
/*   Updated: 2020/02/15 17:40:28 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

long long int	get_time(void)
{
	struct timeval	tstart;

	gettimeofday(&tstart, NULL);
	return (tstart.tv_sec * 1000LL + tstart.tv_usec / 1000);
}
