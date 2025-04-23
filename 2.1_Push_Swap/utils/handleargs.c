/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-07 14:44:39 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-04-07 14:44:39 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

char	**splitargs(char *str)
{
	char	**args;

	checkspace(str);
	args = ft_split(str, ' ');
	if (checkvalidargs(args, 0) == 1)
	{
		freeargs(args);
		error();
	}
	return (args);
}

int	checkdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) == 0 && !(str[i] == '-' || str[i] == '+'))
			|| ((str[i] == '-' || str[i] == '+')
				&& (ft_isdigit(str[i + 1]) == 0)))
			return (1);
		i++;
	}
	return (0);
}

int	checkvalidargs(char **args, int i)
{
	long	n;
	int		is_split;

	is_split = i;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 11 || checkdigit(args[i]) == 1)
			return (1);
		i++;
	}
	i = is_split;
	while (args[i])
	{
		n = ft_atol(args[i]);
		if (n < -2147483648 || n > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

void	checkspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			error();
		i++;
	}
}

void	check_equal(t_list **a)
{
	t_list	*temp;
	t_list	*t_next;

	temp = *a;
	while (temp)
	{
		t_next = temp->next;
		while (t_next)
		{
			if (temp->value == t_next->value)
				freestack(a, 1);
			t_next = t_next->next;
		}
		temp = temp->next;
	}
}
