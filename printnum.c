/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printnum.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 14:10:08 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 18:06:59 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	nbprinter(unsigned long n, char *base)
{
	unsigned int len;

	len = ft_strlen(base);
	if (n >= len)
		nbprinter(n / len, base);
	write(1, &base[n % len], 1);
}

int	print_signed(int number, t_flags flags)
{
	int 	nlen;
	int 	clen;
	char	blanks;

	blanks = flags.zero && !flags.minus && !flags.isprec ? '0': ' ';
	nlen = get_len(number, 10, 1);
	if (flags.precision == 0 && flags.isprec && number == 0)
		nlen = 0;
	clen = (flags.precision > nlen) ? flags.precision : nlen;
	if (number < 0)
		clen++;
	!flags.minus && !(blanks == '0') ? nblanks(blanks, flags.field - clen) : 0;
	number < 0 ? nblanks('-', 1) : NULL;
	!flags.minus &&  (blanks == '0') ? nblanks('0', flags.field - clen) : 0;
	nblanks('0', clen - nlen - (number < 0 ? 1 : 0));
	if (!flags.isprec || flags.precision != 0 || number != 0)
	{
		if (number == -2147483648)
		{
			write(1, "2", 1);
			number = -147483648;
		} 
		nbprinter(number < 0 ? -number : number, getbase(flags.type));
	}
	flags.minus ? nblanks(' ', flags.field - clen) : NULL;
	if (clen == 0 && !flags.isprec)
		clen++;
	return (flags.field > clen ? flags.field : clen);
}

int	print_unsign(unsigned int number, t_flags flags)
{
	int 	nlen;
	int 	clen;
	char	blanks;

	blanks = flags.zero && !flags.minus && !flags.isprec ? '0' : ' ';
	nlen = get_len(number, ft_strlen(getbase(flags.type)), 0);
	if (flags.precision == 0 && flags.isprec && number == 0)
		nlen = 0;
	clen = (flags.precision > nlen) ? flags.precision : nlen;
	!flags.minus ? nblanks(blanks, flags.field - clen) : NULL;
	nblanks('0', clen - nlen);
	if (!flags.isprec || flags.precision != 0 || number != 0)
	nbprinter(number, getbase(flags.type));
	flags.minus ? nblanks(' ', flags.field - clen) : NULL;
	if (clen == 0 && !flags.isprec)
		clen++;
	return (flags.field > clen ? flags.field : clen);
}