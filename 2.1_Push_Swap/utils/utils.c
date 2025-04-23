/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-09 13:30:12 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-04-09 13:30:12 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	freeargs(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	freestack(t_list **lst, int iserror)
{
	t_list	*node;
	t_list	*n_node;

	if (!lst)
		return ;
	node = *lst;
	while (node != NULL)
	{
		n_node = node->next;
		free(node);
		node = n_node;
	}
	free(node);
	if (iserror != 0)
		error();
}

long	ft_atol(const char *nptr)
{
	int				i;
	long long int	n;
	int				sign;

	i = 0;
	sign = 1;
	n = 0;
	if (ft_strncmp(nptr, "-2147483648", 11) == 0)
		return (-2147483648);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}

int	stacklen(t_list **stack)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
