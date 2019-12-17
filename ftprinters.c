/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftprinters.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 13:36:51 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 20:06:22 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ftprintf.h"

int	print_number(int number, t_flags flags)
{
	(void)flags;
	if (flags.type == 'd'|| flags.type == 'i')
		ft_putnbr_base_fd((int)number, 1, DECIMAL);
	if (flags.type == 'u')
		ft_putnbr_base_unsigned_fd((int)number, 1, DECIMAL);
	if(flags.type == 'x')
		ft_putnbr_base_unsigned_fd((int)number, 1, HEXA_LOW);
	if(flags.type == 'X')
		ft_putnbr_base_unsigned_fd((int)number, 1, HEXA_UPP);
	return (0);
}

int	print_pointr(unsigned long number, t_flags flags)
{
	(void)flags;
	ft_putstr_fd("0x", 1);
	ft_putnbr_ulong_fd(number, 1, HEXA_LOW);
	return (0);
}

int	print_charac(char c, t_flags flags)
{
	if (flags.type == '%')
		write(1, "%", 1);
	else
		write(1, &c, 1);
	return (1);
}

int	print_string(char *string, t_flags flags)
{
	(void)flags;
	write(1, string, ft_strlen(string));
	return(ft_strlen(string));
}
