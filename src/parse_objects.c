/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:28 by trifflet          #+#    #+#             */
/*   Updated: 2020/02/26 18:20:00 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int		feed(t_linefeed *linefeed, char *line)
{
	t_linefeed *new;

	if (!(new = malloc(sizeof(t_linefeed))))
		return (ERROR);
	new->line = line;
	new->next = NULL;
	while (linefeed->next)
		linefeed = linefeed->next;
	linefeed->next = new;
	return (0);
}

void	feed_free(t_linefeed **feed)
{
	t_linefeed *tmp;

	tmp = (*feed)->next;
	free((*feed)->line);
	free(*feed);
	*feed = tmp;
}

char	**construct_map(t_linefeed *feed, int number_line, int max_line_len)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = malloc(sizeof(char*) * number_line)))
		return (NULL);
	while (i < number_line)
	{
		if (!(map[i] = malloc(sizeof(char) * max_line_len + 1)))
			break ;
		j = 0;
		while (j < max_line_len && feed->line[j])
		{
			map[i][j] = feed->line[j];
			j++;
		}
		while (j < max_line_len)
			map[i][j++] = '0';
		map[i][max_line_len] = '\0';
		i++;
		feed_free(&feed);
	}
	return (map);
}

int		get_map(char *line, int fd, t_data *data)
{
	int			control;
	int			number_line;
	int			max_line_len;
	t_linefeed	*linefeed;

	if (!(linefeed = malloc(sizeof(t_linefeed))))
		return (ERROR);
	linefeed->next = NULL;
	linefeed->line = line;
	number_line = 1;
	control = 1;
	max_line_len = 0;
	max_line_len = max(max_line_len, ft_strlen(line));
	while (control == 1)
	{
		control = get_next_line(fd, &line);
		control += check_sequence(line, "36", line);
		number_line++;
		max_line_len = max(max_line_len, ft_strlen(line));
		if (feed(linefeed, line))
			return (ERROR);
	}
	data->map.map = construct_map(linefeed, number_line, max_line_len);
	data->map.height = number_line;
	data->map.width = max_line_len;
	for (int f = 0; f < number_line; f++)
		printf("%s\n", data->map.map[f]);
	return (check_map(data));
}
