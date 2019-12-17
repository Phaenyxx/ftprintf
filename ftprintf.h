/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftprintf.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:46:52 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 17:44:21 by trifflet    ###    #+. /#+    ###.fr     */
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

typedef struct	s_flags
{
	int type;
	int	field;
	int precision;
	int zero;
	int minus;
	
}				t_flags;

int				ft_printf(const char *, ...)__attribute__ ((format (printf, 1, 2)));;

int				is_conv(char x);
int				evaluate(char *str, va_list *args);
int				print_number(int number, t_flags flags);
int				print_pointr(unsigned long number, t_flags flags);
int				print_charac(char c, t_flags flags);
int				print_string(char *string, t_flags flags);
#endif
