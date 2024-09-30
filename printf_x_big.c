/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:04:26 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/30 13:42:41 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"

static int	ft_hex_num_len(unsigned int arg_hex_number_upper)
{
	int	i;

	i = 0;
	while (arg_hex_number_upper > 16)
	{
		i++;
		arg_hex_number_upper = arg_hex_number_upper / 16;
	}
	i++;
	return (i);
}

static void	ft_put_nbr_hex_upper(unsigned int arg_hex_number_upper)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (arg_hex_number_upper >= 16)
	{
		ft_put_nbr_hex_upper(arg_hex_number_upper / 16);
		ft_put_nbr_hex_upper(arg_hex_number_upper % 16);
	}
	else if (arg_hex_number_upper < 16)
		ft_putchar_fd(hex[arg_hex_number_upper], 1);
	return ;
}

int	ft_printf_x_big(va_list params, int len)
{
	unsigned int	arg_hex_number_upper;

	arg_hex_number_upper = va_arg(params, unsigned int);
	len = len + ft_hex_num_len(arg_hex_number_upper);
	ft_put_nbr_hex_upper(arg_hex_number_upper);
	return (len);
}
