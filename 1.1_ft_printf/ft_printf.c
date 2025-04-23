/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-12 12:04:38 by cpinho-c          #+#    #+#             */
/*   Updated: 2024-12-12 12:04:38 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_args(va_list args, char c);

int	ft_printf(const char *mand, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, mand);
	i = 0;
	len = 0;
	while (mand[i])
	{
		if (mand[i] == '%')
		{
			i++;
			len += print_args(args, mand[i]);
		}
		else
		{
			ft_putchar_fd(mand[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

static int	print_args(va_list args, char c)
{
	if (c == 'c')
		return (printf_char(va_arg(args, int)));
	else if (c == '%')
		return (printf_char('%'));
	else if (c == 's')
		return (printf_str(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (printf_digits(va_arg(args, int)));
	else if (c == 'u')
		return (printf_uns(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (printf_hex(va_arg(args, int), c));
	else if (c == 'p')
		return (printf_ptr(va_arg(args, void *)));
	else
		return (0);
}

// #include <stdio.h>
// #include "ft_printf.h"
// #include <limits.h>

// int main ()
// {
// 	unsigned long hex = LONG_MIN;
// 	char c = 'f';
// 	char *str = "hello world";
// 	int n = -2147483648;
// 	unsigned int n2 = 4294967295;
// 	unsigned long *ptr = &hex;
// 	int i = printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
// 	printf("printf%d\n", i);
// 	ft_printf("lowhex = %x\nuphex = %X\nchar = %c\nstr = %s\ndigit i = %i\ndigit d = %d\nunsigned = %u\npercent = %%\npointer = %p\nYipee!!!\n",
// 		hex, hex, c, str, n, n, n2, ptr);
// 	i = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	ft_printf("ftprin%d", i);
// 	return (0);
// }