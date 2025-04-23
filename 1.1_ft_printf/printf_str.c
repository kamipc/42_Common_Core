/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-12 12:07:37 by cpinho-c          #+#    #+#             */
/*   Updated: 2024-12-12 12:07:37 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	printf_str(char *str)
{
	if (!str)
		return (printf_str("(null)"));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
