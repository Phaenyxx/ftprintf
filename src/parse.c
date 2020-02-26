/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:11:04 by trifflet          #+#    #+#             */
/*   Updated: 2020/02/26 15:50:50 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../header/cub3d.h"

int		check_sequence(char *line, char *sequence, char *control)
{
	while (*sequence && *line)
	{
		control = line;
		while (*sequence == SEQ_SPACE && is_in(*line, " 	"))
			line++;
		while (*sequence == SEQ_NRSPACE && is_in(*line, " 	"))
			line++;
		while (*sequence == SEQ_ID && is_in(*line, "RNSEWCFOA"))
			line++;
		while (*sequence == SEQ_TEXT && is_in(*line,\
			"-_./abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"))
			line++;
		while (*sequence == SEQ_NUM && is_in(*line, "0123456789"))
			line++;
		if (*sequence == SEQ_COMMA && is_in(*line, ","))
			line++;
		if (*sequence != SEQ_NRSPACE && line == control)
			return (ERROR);
		sequence++;
		if (!*line && (!*sequence ||\
			(*sequence == SEQ_NRSPACE && !(*(sequence + 1)))))
			return (0);
	}
	return (ERROR);
}

int		get_color(char *line, t_data *data, int type)
{
	if (check_sequence(line, "1534634636", line))
		return (ERROR);
	if (type == FLOOR_COLOR)
	{
		data->sprites.floor.red = ft_atoi(skip(line, 1));
		data->sprites.floor.green = ft_atoi(skip(line, 2));
		data->sprites.floor.blue = ft_atoi(skip(line, 3));
		data->sprites.ceiling.alpha = 0;
	}
	else if (type == CEILING_COLOR)
	{
		data->sprites.ceiling.red = ft_atoi(skip(line, 1));
		data->sprites.ceiling.green = ft_atoi(skip(line, 2));
		data->sprites.ceiling.blue = ft_atoi(skip(line, 3));
		data->sprites.ceiling.alpha = 0;
	}
	return (type);
}

int		get_resolution(char *line, t_data *data)
{
	if (check_sequence(line, "153536", line))
		return (ERROR);
	data->window.width = ft_atoi(skip(line, 1));
	data->window.height = ft_atoi(skip(line, 2));
	return (RESOLUTION);
}

int		analyze(char *line, t_data *data, int *mask)
{
	if (!line || check_line(line))
		return (-1);
	if (*line == '1' || *line == '0')
		return (1);
	if (*line == 'R')
		*mask += get_resolution(line, data);
	if (*line == 'F')
		*mask += get_color(line, data, FLOOR_COLOR);
	if (*line == 'C')
		*mask += get_color(line, data, CEILING_COLOR);
	free(line);
	return (0);
}

int		get_infos(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		end;
	int		mask;

	end = 1;
	mask = 0;
	fd = open(file, O_RDONLY);
	while (end && end < 2 && !(mask % 2))
	{
		end = get_next_line(fd, &line);
		end += analyze(line, data, &mask);
	}
	data->map.validity = 1;
	mask += get_map(line, fd, data);
	return (!((mask & 1023) ==\
		RESOLUTION + FLOOR_COLOR + CEILING_COLOR + MAP_GET));
}
