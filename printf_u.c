/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:07:31 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/30 13:49:32 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"

static int	ft_number_len(int arg_unsigned_number)
{
	int	i;

	i = 0;
	while (arg_unsigned_number > 10)
	{
		i++;
		arg_unsigned_number = arg_unsigned_number / 10;
	}
	i++;
	return (i);
}

int	ft_printf_u(va_list params, int len)
{
	unsigned int	arg_unsigned_number;

	arg_unsigned_number = va_arg(params, unsigned int);
	ft_putnbr_fd(arg_unsigned_number, 1);
	len = len + ft_number_len(arg_unsigned_number);
	return (len);
}
