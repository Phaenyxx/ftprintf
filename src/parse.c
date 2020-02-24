/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:11:04 by trifflet          #+#    #+#             */
/*   Updated: 2020/02/20 17:11:30 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../header/cub3d.h"

char	*skip(char *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		while (*str != ' ')
			str++;
		while (*str == ' ')
			str++;
		i++;
	}
	return (str);
}

int		analyze(char *line, t_data *data)
{
	if (!line)
		return (0);
	ft_printf("%s\n", line);
	if (*line == '1')
		return (1);
	if (*line == 'R')
	{
		data->window.width = ft_atoi(skip(line, 1));
		data->window.height = ft_atoi(skip(line, 2));
	}
	free(line);
	return (0);
}

int		get_infos(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		end;

	end = 1;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	while (end && end < 2)
	{
		end = get_next_line(fd, &line);
		end += analyze(line, data);
	}
	ft_printf("%s", line);
	return (0);
}
