/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:06:16 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/30 13:46:09 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"

int	ft_printf_d(va_list params, int len)
{
	int	arg_digit;

	arg_digit = va_arg(params, int);
	if (arg_digit < 0)
		len++;
	ft_putnbr_fd(arg_digit, 1);
	len++;
	return (len);
}
