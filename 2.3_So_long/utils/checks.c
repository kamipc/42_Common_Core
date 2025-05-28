/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 16:59:26 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-18 16:59:26 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



void	check_valid_map(t_game *game)
{
	int	i;

	i = 0;
	// ft_printf("testec\n");
	if (wall_check(game->map) == false)
		call_error(2, game);
	// ft_printf("tested\n");
	if (player_check(game) == false)
		call_error(3, game);
	// ft_printf("testee\n");
	if (exit_check(game->map) == false)
		call_error(4, game);
	// ft_printf("testef\n");
	if (items_check(game) == false)
		call_error(5, game);
	// ft_printf("testeg\n");
	if (map_is_ret_check(game->map) == false)
		call_error(6, game);
	// ft_printf("testeh\n");
}

