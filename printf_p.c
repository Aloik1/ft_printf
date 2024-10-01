/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:38:39 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/01 17:04:44 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"

static int	ft_hex_num_len(size_t num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

static void	ft_put_nbr_hex_ptr(size_t num)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num >= 16)
	{
		ft_put_nbr_hex_ptr(num / 16);
		ft_put_nbr_hex_ptr(num % 16);
	}
	else if (num < 16)
		ft_putchar_fd(hex[num], 1);
	return ;
}

int	ft_printf_p(size_t c)
{
	ft_putstr_fd("0x", 1);
	ft_put_nbr_hex_ptr(c);
	return (2 + ft_hex_num_len(c));
}
