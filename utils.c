/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 12:19:18 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 11:48:31 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int			get_len(long n, int base, int is_signed)
{
	int m;

	m = 0;
	if (is_signed)
		while (n)
		{
			n /= base;
			m++;
		}
	else
		while (n != 0)
		{
			n = (unsigned long)n / base;
			m++;
		}
	if (m == 0)
		m++;
	return (m);
}

void		nblanks(char c, int n)
{
	while (n-- > 0)
		write(1, &c, 1);
}

int			ft_strlen(const char *str)
{
	return (*str ? 1 + ft_strlen(str + 1) : 0);
}

static int	ft_isspace(char c)
{
	return (((c >= '\t' && c <= '\r') || (c == ' ')) ? 1 : 0);
}

int			ft_atoi(const char *str)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + (*(str++) - '0');
	return (nb * sign);
}
