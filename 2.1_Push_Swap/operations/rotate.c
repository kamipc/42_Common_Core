/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-09 17:36:09 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-04-09 17:36:09 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

// The first element becomes the last one.
void	rotate_if(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		rotate(a);
		ft_printf("ra\n");
	}
	else if (op == 1)
	{
		rotate(b);
		ft_printf("rb\n");
	}
	else if (op == 2)
	{
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
	}
}

void	rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*get_last;

	temp = *lst;
	*lst = (*lst)->next;
	get_last = *lst;
	while (get_last->next != NULL)
	{
		get_last = get_last->next;
	}
	temp->next = NULL;
	get_last->next = temp;
}
