/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:35:48 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/29 21:07:53 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"
#include <stdio.h>

int	ft_many_ifs(const char *str, int len, va_list params)
{
	if (str[len] == ' ')
			ft_putchar_fd(' ', 1);
	if (str[len] == '%')
	{
		len++;
		if (str[len] == 'c')
			return (ft_printf_c(params, len));
		if (str[len] == 'd')
			return (ft_printf_d(params, len));
		if (str[len] == 's')
			return (ft_printf_s(params, len));
		if (str[len] == 'i')
			return (ft_printf_i(params, len));
		if (str[len] == 'u')
			return (ft_printf_u(params, len));
		if (str[len] == 'x')
			return (ft_printf_x(params, len));
		if (str[len] == 'X')
			return (ft_printf_X(params, len));
		if (str[len] == 'p')
			return (ft_printf_p(params, len));
	}
	else
		ft_putchar_fd(str[len], 1);
	return (len);
}
int	ft_printf(const char *str, ...)
{
	va_list params;
	va_start(params, str); //indica el ultimo argumento fijo

	int	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == ' ')
			ft_putchar_fd(' ', 1);
		if (str[len] == '%')
			ft_many_ifs(str, len, params);
		len++;
	}
	va_end(params);
	return (len);
}	
// int	main(void)
// {
// 	ft_printf("%s %d %c %x\n", "Hello", 5, 'W', 1000000);
// 	printf("%s %d %c %x\n", "Hello", 5, 'W', 1000000);
// 	ft_printf("%c %i %u", 'A', 123, 321);
// 	printf("%c %i %u", 'A', 123, 321);
// 	return (0);
// }