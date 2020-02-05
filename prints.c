/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prints.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 13:36:51 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 17:18:21 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char *getbase(char c)
{
	if (c == 'u')
		return (DECIMAL);
	if (c == 'x')
		return (HEXA_LOW);
	if (c == 'X')
		return (HEXA_UPP);
	return (DECIMAL);
}

int	print_pointr(unsigned long number, t_flags flags)
{
	int ret;

	ret = flags.field > get_len(number, 16, 1) + 2 ? flags.field :\
		get_len(number, 16, 1) + 2;
	if (!flags.minus)
		nblanks(' ', flags.field - 2 - get_len(number, 16, 1));
	write(1, "0x", 2);
	nbprinter(number, HEXA_LOW);
	if (flags.minus)
		nblanks(' ', flags.field - 2 - get_len(number, 16, 1));
	return (ret);
}

int	print_charac(char c, t_flags flags)
{
	if (!flags.minus)
		nblanks(' ', flags.field - 1);
	if (flags.type == '%')
		write(1, "%", 1);
	else
		write(1, &c, 1);
	if (!flags.minus)
		nblanks(' ', flags.field - 1);
	return (1);
}

int	print_string(char *string, t_flags flags)
{
	size_t len; 
	size_t print;
	
	len = ft_strlen(string);
	print = flags.precision < (int)len ? flags.precision : len;
	if (!flags.minus)
		nblanks(' ', flags.field - print);
	write(1, string, print);
	if (flags.minus)
		nblanks(' ', flags.field - print);
	return((int)print > flags.field ? print : flags.field);
}
