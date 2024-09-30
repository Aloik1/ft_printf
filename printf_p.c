/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:38:39 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/30 13:47:43 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"

static int	ft_hex_num_len(size_t arg_ptr)
{
	int	i;

	i = 0;
	if (arg_ptr == 0)
		return (1);
	while (arg_ptr > 0)
	{
		arg_ptr = arg_ptr / 16;
		i++;
	}
	return (i);
}

static void	ft_put_nbr_hex_ptr(size_t arg_ptr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (arg_ptr >= 16)
	{
		ft_put_nbr_hex_ptr(arg_ptr / 16);
		ft_put_nbr_hex_ptr(arg_ptr % 16);
	}
	else if (arg_ptr < 16)
	{
		ft_putchar_fd(hex[arg_ptr], 1);
	}
	return ;
}

int	ft_printf_p(va_list params, int len)
{
	void	*arg_ptr;

	arg_ptr = va_arg(params, void *);
	ft_putstr_fd("0x", 1);
	len = len + 2;
	if (!arg_ptr)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	else
	{
		len = len + ft_hex_num_len((size_t)arg_ptr);
		ft_put_nbr_hex_ptr((size_t)arg_ptr);
	}
	return (len);
}
