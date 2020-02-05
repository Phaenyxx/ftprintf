/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 18:01:03 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 17:17:52 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "printf.h"
# include "color.h"

int main(int ac, char **av)
{
    int *test;
    if (ac == 1)
        return(0);
    int n = ft_atoi(av[1]);
    test = malloc(sizeof(int));
    /*ft_printf("%c "RED"."RST" %s "RED"."RST" %p "RED"."RST" %d "RED"."RST" %u\
     "RED"."RST" %x "RED"."RST" %X\n\n", 'a', "test", test, 345, -3, 3456, HEXA_LOW4);
    printf("%c "RED"."RST" %s "RED"."RST" %p "RED"."RST" %d "RED"."RST" %u\
     "RED"."RST" %x "RED"."RST" %X\n", 'a', "test", test, 345, -3, 3456, HEXA_LOW4);*/
    // printf(av[2], n);
    (void)n;
    printf("%d\n",printf(".%p.", HEXA_LOW));
    printf("%d\n",ft_printf(".%p.", HEXA_LOW));
    printf("%d\n",printf(".%16p.", HEXA_LOW));
    printf("%d\n",ft_printf(".%16p.", HEXA_LOW));
    /*printf("%d\n",printf(".%.13p.", HEXA_LOW));
    printf("%d\n",ft_printf(".%.13p.", HEXA_LOW));
    printf("%d\n",printf(".%-13p.", HEXA_LOW));
    printf("%d\n",ft_printf(".%-13p.", HEXA_LOW));
    printf("%d\n",printf(".%-.13p.", HEXA_LOW));
    printf("%d\n",ft_printf(".%-.13p.", HEXA_LOW));
    printf("%d\n",printf(".%.13p.", HEXA_LOW));
    printf("%d\n",ft_printf(".%.13p.", HEXA_LOW));
    printf("%d\n",printf(".%16.13p.", HEXA_LOW));
    printf("%d\n",ft_printf(".%16.13p.", HEXA_LOW));
    printf("%d\n",printf(".%-16.13p.", HEXA_LOW));
    printf("%d\n",ft_printf(".%-16.13p.", HEXA_LOW));
    printf("%d\n",printf(".%16.13p.", HEXA_LOW));
    printf("%d\n",ft_printf(".%16.13p.", HEXA_LOW));*/
}