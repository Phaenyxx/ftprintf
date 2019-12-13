/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftprintf.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:46:52 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 14:07:22 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "unistd.h"
# include "color.h"
# include "libft/libft.h"

# define UNUSED(x)      (void)(x)
# define ISCONVERTER(x) ((x) == 'c' || (x) == 's' || (x) == 'd' || (x) == 'i' ||\
                            (x) == 'u' || (x) == 'x' || (x) == 'X' || (x) == '%')

int		ft_printf(const char *, ...)__attribute__ ((format (printf, 1, 2)));;
int		gettypeandflags(char *format, int *flags);
char    *format_number(void *content, int precision, int flags);
char    *format_pointr(void *content, int precision, int flags);
void	print_charac(void *content, int precision, int flags);
void	print_string(void *content, int precision, int flags);
void	print_percnt(void);

#endif
