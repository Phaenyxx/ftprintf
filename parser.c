/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 17:50:23 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 20:06:47 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ftprintf.h"

int		is_conv(char x)
{
if ((x) == 'c' || (x) == 's' || (x) == 'd' || (x) == 'i' || (x) == 'p' ||\
	(x) == 'u' || (x) == 'x' || (x) == 'X' || (x) == '%' )
	return (1);
	return (0);
}

t_flags	decrypt(char *str)
{
	t_flags flags;
	
	flags.field = -1;
	flags.precision = -1;
	while (!is_conv(*str))
		str++;
	flags.type = *str;
	return (flags);
}

int		evaluate(char *str, va_list *args)
{
	t_flags flags;
	
	flags = decrypt(str + 1);
	flags.field = flags.field == -2 ? va_arg(*args, int) : -1;
	flags.precision = flags.precision == -2 ? va_arg(*args, int) : -1;
	if (flags.type == 'c' || flags.type == '%')
		return(print_charac(va_arg(*args, int), flags));
	if (flags.type == 'd' || flags.type == 'i' || flags.type == 'u' ||\
		flags.type == 'x' || flags.type == 'X')
		return(print_number(va_arg(*args, int), flags));
	if (flags.type == 's')
		return(print_string(va_arg(*args, char *), flags));
	if (flags.type == 'p')
		return(print_pointr(va_arg(*args, unsigned long), flags));
	return (0);
}