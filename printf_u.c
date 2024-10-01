/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:07:31 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/01 16:45:40 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_lib_utils.h"

static int	ft_number_len(unsigned int num)
{
	int	i;

	i = 0;
	while (num > 10)
	{
		i++;
		num = num / 10;
	}
	i++;
	return (i);
}

int	ft_printf_u(unsigned int c)
{
	ft_putnbr_fd(c, 1);
	return(ft_number_len(c));
}
