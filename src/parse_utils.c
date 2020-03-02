/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:24:46 by trifflet          #+#    #+#             */
/*   Updated: 2020/03/02 12:33:28 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		max(int a, int b)
{
	return (a > b ? a : b);
}

int		is_in(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*skip(char *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		while (*str != ' ' & *str != ',')
			str++;
		while (*str == ' ' || *str == ',')
			str++;
		i++;
	}
	return (str);
}

int		check_line2(char *line, char *set)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!is_in(line[i++], set) && *line)
			return (-1);
	}
	return (0);
}

int		check_line(char *line, char *set)
{
	if (!is_in(*line, set) && *line)
		return (-1);
	return (0);
}
