/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printnum.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 14:10:08 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 17:15:49 by trifflet    ###    #+. /#+    ###.fr     */
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
	int nlen;
	int clen;

	nlen = get_len(number, 10, 1);
	clen = (flags.precision > nlen) ? flags.precision : nlen;
	if (number < 0)
		clen++;
	!flags.minus ? nblanks(' ', flags.field - clen) : NULL;
	number < 0 ? nblanks('-', 1): NULL;
	nblanks('0', clen - nlen - (number < 0 ? 1 : 0));
	nbprinter(number < 0 ? -number : number, getbase(flags.type));
	flags.minus ? nblanks(' ', flags.field - clen) : NULL;
	return (flags.field > clen ? flags.field : clen);
}

int	print_unsign(unsigned int number, t_flags flags)
{
	int nlen;
	int clen;


	nlen = get_len(number, ft_strlen(getbase(flags.type)), 0);
	clen = (flags.precision > nlen) ? flags.precision : nlen;
	!flags.minus ? nblanks(' ', flags.field - clen) : NULL;
	nblanks('0', clen - nlen);
	nbprinter(number, getbase(flags.type));
	flags.minus ? nblanks(' ', flags.field - clen) : NULL;
	return (flags.field > clen ? flags.field : clen);
	return (0);
}