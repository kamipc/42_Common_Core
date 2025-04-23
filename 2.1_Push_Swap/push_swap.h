/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:26:38 by cpinho-c          #+#    #+#             */
/*   Updated: 2025/04/09 15:26:51 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

void	error(void);
char	**splitargs(char *str);
int		checkvalidargs(char **args, int i);
void	freeargs(char **args);
t_list	*initstack_a(char **args, int i);
t_list	*newnode(char *str);
void	freestack(t_list **lst, int iserror);
void	checkspace(char *str);
long	ft_atol(const char *nptr);
void	swap_if(t_list **a, t_list **b, int op);
void	swap(t_list **lst);
void	push_if(t_list **a, t_list **b, int op);
void	push(t_list **leavelst, t_list **golst);
void	rotate_if(t_list **a, t_list **b, int op);
void	rotate(t_list **lst);
void	rev_rotate_if(t_list **a, t_list **b, int op);
void	rev_rotate(t_list **lst);
void	check_equal(t_list **a);
void	sort_index(t_list **stack);
bool	check_index(t_list **a);
bool	checksorted(t_list **stack);
int		stacklen(t_list **stack);
int		getlastindex(t_list **a);
void	ft_sort(t_list **a);
void	sort_2(t_list **stack);
void	sort_3(t_list **stack);
void	sort_4(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);
void	ft_radix(t_list **a, t_list **b, int a_len);
// void	printlst(t_list **lst);
#endif