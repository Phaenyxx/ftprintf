/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:46:02 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 12:58:18 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char	*cutter(char *to_cut, int *i)
{
	int		len;
	char	*cut;

	len = 1;
	cut = NULL;
	while (!is_conv(to_cut[len]))
		len++;
	len++;
	if (!(cut = malloc(sizeof(char) + len)))
		return (NULL);
	*i += len;
	while (len--)
		cut[len] = to_cut[len];
	return (cut);
}

void	send(const char *text, int start, int end)
{
	if (start < end)
		write(1, text + start, end - start);
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
	while (in[i])
	{
		if (in[i] == '%')
		{
			send(in, start, i);
			len += evaluate(cutter((char *)&in[i], &i), &args);
			start = i--;
		}
		else
			len++;
		i++;
	}
	send(in, start, i);
	va_end(args);
	return (len);
}
