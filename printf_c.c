/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:05:52 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/29 20:15:00 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"

int	ft_printf_c(va_list params, int len)
{
	char arg_char = va_arg(params, int);
	ft_putchar_fd(arg_char, 1);
	len++;
	return (len);
}