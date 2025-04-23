/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 13:32:25 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-04-11 13:32:25 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

bool	checksorted(t_list **stack)
{
	t_list	*temp;
	t_list	*t_next;
	int		islower;

	temp = *stack;
	while (temp)
	{
		islower = temp->value;
		t_next = temp->next;
		while (t_next)
		{
			if (islower > t_next->value)
				return (false);
			t_next = t_next->next;
		}
		temp = temp->next;
	}
	return (true);
}

void	sort_index(t_list **stack)
{
	t_list	*temp;
	t_list	*t_next;
	int		i;

	i = 0;
	while (!check_index(stack))
	{
		temp = *stack;
		while (temp)
		{
			t_next = *stack;
			while (t_next)
			{
				if (temp->value > t_next->value && t_next->index == -1)
					break ;
				else if (t_next->next == NULL && temp->index == -1)
				{
					temp->index = i;
					i++;
				}
				t_next = t_next->next;
			}
			temp = temp->next;
		}
	}
}

bool	check_index(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->index == -1)
			break ;
		else if (temp->next == NULL)
			return (true);
		temp = temp->next;
	}
	return (false);
}

void	ft_sort(t_list **a)
{
	t_list	*b;

	b = NULL;
	sort_index(a);
	if (checksorted(a))
		exit(0);
	else if (stacklen(a) == 2)
		sort_2(a);
	else if (stacklen(a) == 3)
		sort_3(a);
	else if (stacklen(a) == 4)
		sort_4(a, &b);
	else if (stacklen(a) == 5)
		sort_5(a, &b);
	else
		ft_radix(a, &b, stacklen(a));
}

int	getlastindex(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp->index);
}
