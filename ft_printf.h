/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:37:26 by aloiki            #+#    #+#             */
/*   Updated: 2024/09/30 13:43:15 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printf_c(va_list params, int len);
int	ft_printf_d(va_list params, int len);
int	ft_printf_s(va_list params, int len);
int	ft_printf_i(va_list params, int len);
int	ft_printf_u(va_list params, int len);
int	ft_printf_x(va_list params, int len);
int	ft_printf_x_big(va_list params, int len);
int	ft_printf_p(va_list params, int len);
//utils
// int	ft_putchar_fd(char c, int fd);
// int	ft_putstr_fd(char *s, int fd);
// int	ft_putnbr_fd(int nb, int fd);

#endif