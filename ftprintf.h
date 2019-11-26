/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftprintf.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:46:52 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 20:35:37 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define UNUSED(x) (void)(x)

int		ft_printf(const char *, ...);
int		gettypeandflags(char *format, int *flags);
char	*format_char(void *content, int precision, int flags);
char	*format_strg(void *content, int precision, int flags);
char	*format_prct(void *content, int precision, int flags);
char	*format_numr(void *content, int precision, int flags);
char	*format_usnd(void *content, int precision, int flags);
char	*format_hexa(void *content, int precision, int flags);
char	*format_pntr(void *content, int precision, int flags);

#endif
