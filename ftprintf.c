/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftprintf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:46:02 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 14:01:05 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ftprintf.h"


char	*cutter(char *to_cut, int *i)
{
	int len;
	char *cut;

	len = 1;
	cut = NULL;
	while (!ISCONVERTER(to_cut[len]))
		len++;
	len++;
	if(!(cut = malloc(sizeof(char) + len)))
		return (NULL);
	*i += len;

	while(len--)
		cut[len] = to_cut[len];
	return (cut);
}

int		evaluate(char *str)
{
	ft_putstr_fd(RED, 0);
	ft_putstr_fd(str, 0);
	ft_putstr_fd(RST, 0);
	free(str);
	return (0);
}

void	send(const char *text, int start, int end)
{
	if (start < end)
		write (1, text + start, end - start);
}

int		ft_printf(const char *in, ...)
{
	va_list	args;
	int		i;
	int		start;
	int		len;

	va_start(args, in);
	i = 0;
	len = 0;
	start = 0;
	while(in[i])
	{
		if (in[i] == '%')
		{
			send(in, start, i);
			len += evaluate(cutter((char *)&in[i], &i));
			start = i + 1;
		}
		else
			len++;
		i++;
	}
	send(in, start, i);
	return (len);
}
