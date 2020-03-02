/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:11:04 by trifflet          #+#    #+#             */
/*   Updated: 2020/03/02 19:27:36 by trifflet         ###   ########lyon.fr   */
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
		return (0);
	if (type == FLOOR_COLOR)
	{
		data->sprites.floor.red = ft_atoi(skip(line, 1));
		data->sprites.floor.green = ft_atoi(skip(line, 2));
		data->sprites.floor.blue = ft_atoi(skip(line, 3));
		data->sprites.floor.alpha = (char)200;
	}
	else if (type == CEILING_COLOR)
	{
		data->sprites.ceiling.red = ft_atoi(skip(line, 1));
		data->sprites.ceiling.green = ft_atoi(skip(line, 2));
		data->sprites.ceiling.blue = ft_atoi(skip(line, 3));
		data->sprites.ceiling.alpha = (char)200;
	}
	return (type);
}

int		get_resolution(char *line, t_data *data)
{
	if (check_sequence(line, "153536", line))
		return (0);	
	data->window.w = ft_atoi(skip(line, 1));
	data->window.h = ft_atoi(skip(line, 2));
	return (RESOLUTION);
}

int		analyze(char *line, t_data *data, int fd)
{
	int ret;

	ret = 0;
	if (!line || check_line(line, "RNSEWCFOA10"))
		return (-1);
	if (*line == '1' || *line == '0')
		ret = get_map(line, fd, data);
	if (*line == 'R')
		ret = get_resolution(line, data);
	if (*line == 'F')
		ret = get_color(line, data, FLOOR_COLOR);
	if (*line == 'C')
		ret = get_color(line, data, CEILING_COLOR);
	if (ret != MAP_GET)
		free(line);
	return (ret);
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
	data->map.validity = 1;
	while (end && !(mask % 2) && !(mask & MAP_GET))
	{
		end = get_next_line(fd, &line);
		mask += analyze(line, data, fd);
	}
	return (mask);
}
