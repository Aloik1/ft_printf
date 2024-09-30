/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:35:48 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/30 13:43:28 by ikondrat         ###   ########.fr       */
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
			return (ft_printf_x_big(params, len));
		if (str[len] == 'p')
			return (ft_printf_p(params, len));
	}
	else
		ft_putchar_fd(str[len], 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		len;

	va_start(params, str);
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
// 	char	*str;

// 	str = "UwU";
// 	ft_printf("%s %d %c %x %p", "Hello", 5, 'W', 1000000, str);
// 	printf("\n");
// 	printf("%s %d %c %x %p\n", "Hello", 5, 'W', 1000000, str);
// 	ft_printf("%c %i %u", 'A', 123, 321);
// 	printf("%c %i %u", 'A', 123, 321);
// 	return (0);
// }