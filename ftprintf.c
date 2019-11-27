/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftprintf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:46:02 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 17:58:19 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ftprintf.h"


/*void	create(char *format, char **ret, void *content, int precision)
{
	int		type;
	int		flags;

	type = gettypeandflags(format, &flags);
}*/

void	send(const char *text, int start, int end)
{
	write (1, text + start, end - start);
}

int		ft_printf(const char *in, ...)
{
	va_list	args;
	int		i;
	int		start;

	va_start(args, in);
	i = 0;
	start = 0;
	while(in[i])
	{
		if (in[i] == '%' || in[i] == '\0')
		{
			send(in, start, i);
		}
	}
	return (i);
}
