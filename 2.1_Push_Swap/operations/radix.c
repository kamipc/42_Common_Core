/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 13:34:19 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-04-16 13:34:19 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	sort_2(t_list **stack)
{
	if (!checksorted(stack))
		swap_if(stack, NULL, 0);
	else
		return ;
}

void	sort_3(t_list **stack)
{
	int	f;
	int	s;
	int	t;

	while (!checksorted(stack))
	{
		f = (*stack)->index;
		s = (*stack)->next->index;
		t = (*stack)->next->next->index;
		if ((f > s && s > t) || (f > s && s < t && f < t)
			|| (f < s && s > t && f < t))
			swap_if(stack, NULL, 0);
		else if (f > s && s < t)
			rotate_if(stack, NULL, 0);
		else if (f < s && s > t)
			rev_rotate_if(stack, NULL, 0);
	}
}

void	sort_4(t_list **a, t_list **b)
{
	if (checksorted(a))
		return ;
	if ((*a)->index == 0)
	{
		push_if(a, b, 1);
		sort_3(a);
		push_if(a, b, 0);
	}
	else if (getlastindex(a) == 0)
	{
		rev_rotate_if(a, b, 0);
		push_if(a, b, 1);
		sort_3(a);
		push_if(a, b, 0);
	}
	else
	{
		while ((*a)->index != 0)
			rotate_if(a, b, 0);
		push_if(a, b, 1);
		sort_3(a);
		push_if(a, b, 0);
	}
}

void	sort_5(t_list **a, t_list **b)
{
	if (checksorted(a))
		return ;
	while (stacklen(b) != 2)
	{
		if (getlastindex(a) == 0 || getlastindex(a) == 1)
		{
			rev_rotate_if(a, b, 0);
			push_if(a, b, 1);
		}
		else if ((*a)->index == 0 || (*a)->index == 1)
			push_if(a, b, 1);
		else
			rotate_if(a, b, 0);
	}
	sort_3(a);
	if ((*b)->index < (*b)->next->index)
		rev_rotate_if(a, b, 1);
	push_if(a, b, 0);
	push_if(a, b, 0);
}

void	ft_radix(t_list **a, t_list **b, int a_len)
{
	int		i_bit;
	int		i;
	t_list	*temp;

	i_bit = 0;
	while (!checksorted(a))
	{
		i = 0;
		while (a && stacklen(a) > 0 && i++ < a_len)
		{
			temp = (*a)->next;
			if ((((*a)->index >> i_bit) & 1) == 0)
				push_if(a, b, 1);
			else
				rotate_if(a, b, 0);
			*a = temp;
		}
		i_bit++;
		while (*b)
		{
			temp = (*b)->next;
			push_if(a, b, 0);
			*b = temp;
		}
	}
}
