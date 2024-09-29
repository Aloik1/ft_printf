/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:06:48 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/29 21:44:39 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"

static int	ft_number_len(int arg_number)
{
	int	i;

	i = 0;
	if (arg_number < 0)
	{
		i++;
		arg_number = -arg_number;
	}
	while (arg_number > 10)
	{
		i++;
		arg_number = arg_number / 10;
	}
		i++;
	return (i);
}
int	ft_printf_i(va_list params, int len)
{
	int arg_number = va_arg(params, int);
	ft_putnbr_fd(arg_number, 1);
	len = len + ft_number_len(arg_number);
	return (len);
}