/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-12 12:05:48 by cpinho-c          #+#    #+#             */
/*   Updated: 2024-12-12 12:05:48 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	printf_digits(int n)
{
	char	*nbr;
	size_t	n_len;

	nbr = ft_itoa(n);
	ft_putstr_fd(nbr, 1);
	n_len = ft_strlen(nbr);
	free(nbr);
	return (n_len);
}
