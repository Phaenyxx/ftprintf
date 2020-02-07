/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:46:52 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 12:15:06 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "color.h"

# define DECIMAL	"0123456789"
# define HEXA_LOW	"0123456789abcdef"
# define HEXA_UPP	"0123456789ABCDEF"

typedef struct	s_flags
{
	int type;
	int	field;
	int precision;
	int isprec;
	int zero;
	int minus;
}				t_flags;

int				ft_printf(const char *str,
		...) __attribute__((format(printf,1,2)));
int				is_conv(char x);

int				get_len(long n, int base, int is_signed);
void			nblanks(char c, int n);
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);

char			*getbase(char c);
int				evaluate(char *str, va_list *args);
void			nbprinter(unsigned long n, char *base);
int				print_signed(int number, t_flags flags);
int				print_unsign(unsigned int number, t_flags flags);
int				print_pointr(unsigned long number, t_flags flags);
int				print_charac(char c, t_flags flags);
int				print_string(char *string, t_flags flags);
#endif
