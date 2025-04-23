/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-09 15:09:23 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-04-09 15:09:23 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

//pa: Take the first element at the top of b and put it at the top of a.
//pb: Take the first element at the top of a and put it at the top of b.
void	push_if(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		push(b, a);
		ft_printf("pa\n");
	}
	else if (op == 1)
	{
		push(a, b);
		ft_printf("pb\n");
	}
}

void	push(t_list **leavelst, t_list **golst)
{
	t_list	*temp;

	if (!*leavelst)
		return ;
	temp = *leavelst;
	*leavelst = (*leavelst)->next;
	if (!*golst)
	{
		*golst = temp;
		(*golst)->next = NULL;
	}
	else
	{
		temp->next = *golst;
		*golst = temp;
	}
}
