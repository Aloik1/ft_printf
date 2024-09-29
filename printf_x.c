/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:03:44 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/29 21:51:16 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"

static int	ft_hex_num_len(unsigned int arg_hex_number_lower)
{
	int	i;

	i = 0;
	while (arg_hex_number_lower > 16)
	{
		i++;
		arg_hex_number_lower = arg_hex_number_lower / 16;
	}
	i++;
	return (i);
}

static void	ft_put_nbr_hex_lower(unsigned int arg_hex_number_lower)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (arg_hex_number_lower >= 16)
	{
		ft_put_nbr_hex_lower(arg_hex_number_lower / 16);
		ft_put_nbr_hex_lower(arg_hex_number_lower % 16);
	}
	else if (arg_hex_number_lower < 16)
		ft_putchar_fd(hex[arg_hex_number_lower], 1);
	return ;
}

int	ft_printf_x(va_list params, int len)
{
	unsigned int arg_hex_number_lower = va_arg(params, unsigned int);
	len = len + ft_hex_num_len(arg_hex_number_lower);
	ft_put_nbr_hex_lower(arg_hex_number_lower);
	return (len);
}
