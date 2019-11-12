/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftprintf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:46:02 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 17:11:03 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ftprintf.h"

void	copyandfree(char *dst, char *src, int n)
{
	       size_t  i;
        char    *csrc;

        i = 0;
        if (dst == NULL && src == NULL)
                return (NULL);
        while (i < n)
        {
                dst[i] = csrc[i];
                i++;
        }
        return (dst);
}

int		create(void **content, int flag)
{

}

int		ft_printf(const char *in, ...)
{
	va_list	args;
	int		i;
	char	*out;
	void	*tmp;

	va_start(args, in);
	i = 0;
	(void)in;
	return (0);
}
