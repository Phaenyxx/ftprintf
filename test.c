/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 18:01:03 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 20:05:16 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "ftprintf.h"
# include "color.h"

int main(int ac, char **av)
{
    int *test;
    (void)ac;
    (void)av;

    test = malloc(sizeof(int));
    ft_printf("%c "RED"."RST" %s "RED"."RST" %p "RED"."RST" %d "RED"."RST" %u\
     "RED"."RST" %x "RED"."RST" %X\n\n", 'a', "test", test, 345, -3, 3456, -1234);
    printf("%c "RED"."RST" %s "RED"."RST" %p "RED"."RST" %d "RED"."RST" %u\
     "RED"."RST" %x "RED"."RST" %X", 'a', "test", test, 345, -3, 3456, -1234);
}