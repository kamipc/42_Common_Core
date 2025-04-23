/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-15 11:41:51 by cpinho-c          #+#    #+#             */
/*   Updated: 2024-11-15 11:41:51 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*count_lst;

	size = 0;
	count_lst = lst;
	while (count_lst)
	{
		count_lst = count_lst->next;
		size++;
	}
	return (size);
}
