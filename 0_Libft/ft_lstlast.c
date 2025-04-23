/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-15 11:47:31 by cpinho-c          #+#    #+#             */
/*   Updated: 2024-11-15 11:47:31 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*get_last;

	if (!lst)
		return (NULL);
	get_last = lst;
	while (get_last->next != NULL)
	{
		get_last = get_last->next;
	}
	return (get_last);
}
