/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftprintf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:46:02 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 21:40:41 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ftprintf.h"


int		create(char *format, char **ret, void *content, int precision)
{
	int		type;
	int		flags;


	type = gettypeandflags(format, &flags);
	
	return ();
}

int		ft_printf(const char *in, ...)
{
	va_list	args;
	int		i;
	char	*out;

	va_start(args, in);
	i = 0;
	(void)in;

	return (0);
}
