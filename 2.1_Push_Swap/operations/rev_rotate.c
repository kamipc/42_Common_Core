/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 13:32:05 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-04-11 13:32:05 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

//The last element becomes the first one.
void	rev_rotate_if(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		rev_rotate(a);
		ft_printf("rra\n");
	}
	else if (op == 1)
	{
		rev_rotate(b);
		ft_printf("rrb\n");
	}
	else if (op == 2)
	{
		rev_rotate(a);
		rev_rotate(b);
		ft_printf("rrr\n");
	}
}

void	rev_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*get_last;

	temp = *lst;
	while (temp)
	{
		get_last = temp->next;
		if (get_last->next == NULL)
			break ;
		temp = temp->next;
	}
	temp->next = NULL;
	get_last->next = *lst;
	*lst = get_last;
}
