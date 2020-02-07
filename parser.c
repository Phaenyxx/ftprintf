/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 17:50:23 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 12:35:10 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int		is_conv(char x)
{
	if ((x) == 'c' || (x) == 's' || (x) == 'd' || (x) == 'i' || (x) == 'p' ||\
		(x) == 'u' || (x) == 'x' || (x) == 'X' || (x) == '%')
		return (1);
	return (0);
}

char	*skip_nums(char *str)
{
	while ('0' <= *str && *str <= '9')
		str++;
	return (str);
}

void	decrypt(t_flags *flags, char *str, va_list *args)
{
	while (*str == '0' || *str == '-')
	{
		flags->zero = *str == '0' ? 1 : flags->zero;
		flags->minus = *str == '-' ? 1 : flags->minus;
		str++;
	}
	flags->field = *str == '*' ? va_arg(*args, int) : ft_atoi(str);
	str = (*str == '*') ? str + 1 : str;
	str = skip_nums(str);
	if (*str == '.')
	{
		flags->precision = *(++str) == '*' ? va_arg(*args, int) : ft_atoi(str);
		flags->isprec = 1;
	}
	if (flags->field < 0)
	{
		flags->field = flags->field < 0 ? flags->field * -1 : flags->field;
		flags->minus = 1;
	}
	while (!is_conv(*str))
		str++;
	flags->type = *str;
}

int		evaluate(char *str, va_list *args)
{
	t_flags flags;

	flags.zero = 0;
	flags.minus = 0;
	flags.isprec = 0;
	flags.precision = 0;
	decrypt(&flags, str + 1, args);
	flags.type = flags.type == 'i' ? 'd' : flags.type;
	if (flags.type == 'c')
		return (print_charac(va_arg(*args, int), flags));
	if (flags.type == '%')
		return (print_charac('%', flags));
	if (flags.type == 'd')
		return (print_signed(va_arg(*args, int), flags));
	if (flags.type == 'u' || flags.type == 'x' || flags.type == 'X')
		return (print_unsign(va_arg(*args, unsigned int), flags));
	if (flags.type == 's')
		return (print_string(va_arg(*args, char *), flags));
	if (flags.type == 'p')
		return (print_pointr(va_arg(*args, unsigned long), flags));
	return (0);
}
