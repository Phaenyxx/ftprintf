/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 18:01:03 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 12:56:25 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include "color.h"

int	main(void)
{
	int *test;

	test = malloc(sizeof(int));
	ft_printf("%c "RED"."RST" %s "RED"."RST" %p "RED"."RST" %d "RED"."RST" %u\
	"RED"."RST" %x "RED"."RST" %X\n\n", 'a', "test", test, 345, -3, 3456, 4);
	printf("%c "RED"."RST" %s "RED"."RST" %p "RED"."RST" %d "RED"."RST" %u\
	"RED"."RST" %x "RED"."RST" %X\n", 'a', "test", test, 345, -3, 3456, 4);
	free(test);
	getchar();
	return (0);
}
