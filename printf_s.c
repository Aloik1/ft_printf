/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:07:09 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/29 20:17:47 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"

int	ft_printf_s(va_list params, int len)
{
	int	i;

	i = 0;
	char *arg_str = va_arg(params, char *);
	while(arg_str[i])
	{
		ft_putchar_fd(arg_str[i], 1);
		len++;
	}
	return (len);
}