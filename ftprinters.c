/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftprinters.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trifflet <trifflet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 13:36:51 by trifflet     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 21:40:40 by trifflet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char *format_number(void *content, int precision, int flags)
{

}

char *format_pointr(void *content, int precision, int flags)
{
	
}

void	print_charac(void *content, int precision, int flags)
{

}

void	print_string(void *content, int precision, int flags)
{
	write(1, content, ft_strlen(content));
}

void	print_percnt(void)
{

	write(1, "%", 1);
}