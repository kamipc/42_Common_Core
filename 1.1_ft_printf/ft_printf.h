/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-12 12:04:48 by cpinho-c          #+#    #+#             */
/*   Updated: 2024-12-12 12:04:48 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *mand, ...);
int	printf_char(char c);
int	printf_str(char *str);
int	printf_digits(int n);
int	printf_uns(unsigned int n);
int	printf_hex(unsigned int n, int state);
int	printf_ptr(void *ptr);

#endif