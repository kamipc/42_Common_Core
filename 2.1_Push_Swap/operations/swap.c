/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-09 14:49:27 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-04-09 14:49:27 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

//Swap the first 2 elements at the top of stack
void	swap_if(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		swap(a);
		ft_printf("sa\n");
	}
	else if (op == 1)
	{
		swap(b);
		ft_printf("sb\n");
	}
	else if (op == 2)
	{
		swap(a);
		swap(b);
		ft_printf("ss\n");
	}
}

void	swap(t_list **lst)
{
	t_list	*temp;
	t_list	*temp_next;

	temp = *lst;
	*lst = (*lst)->next;
	temp_next = (*lst)->next;
	(*lst)->next = temp;
	temp->next = temp_next;
}
