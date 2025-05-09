/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-11 11:38:37 by cpinho-c          #+#    #+#             */
/*   Updated: 2024-12-11 11:38:37 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	prnt_hex(unsigned int n, char *hex);

int	printf_hex(unsigned int n, int state)
{
	int			count;
	char		*uphex;
	char		*lowhex;

	count = 0;
	uphex = "0123456789ABCDEF";
	lowhex = "0123456789abcdef";
	if (state == 88)
		prnt_hex(n, uphex);
	else if (state == 120)
		prnt_hex(n, lowhex);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	prnt_hex(unsigned int n, char *hex)
{
	if (n > 15)
	{
		prnt_hex(n / 16, hex);
		prnt_hex(n % 16, hex);
	}
	else
		ft_putchar_fd(hex[n], 1);
}
