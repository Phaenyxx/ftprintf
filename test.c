/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 18:01:03 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 13:45:54 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "ftprintf.h"
# include "color.h"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    ft_printf("test%12% %ddi%iddi%tgwtrhrdi%s\n");
}