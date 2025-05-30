/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ff_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-29 15:53:44 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-29 15:53:44 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->max_row || y < 0 || y >= game->map->max_col)
		return ;
	if (game->map->cpy_map[x][y] == '1' || game->map->cpy_map[x][y] == 'F')
		return ;
	else
		game->map->cpy_map[x][y] = 'F';
	flood_fill(game, x - 1, y);
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
}

bool	map_impossible(t_game *game)
{
	int	i;

	flood_fill(game, game->player->x, game->player->y);
	i = 0;
	for (int i = 0; game->map->cpy_map[i]; i++)
		ft_printf("%s\n", game->map->cpy_map[i]);
	while (game->map->cpy_map[i])
	{
		if ((ft_strchr(game->map->cpy_map[i], 'C')) 
		|| (ft_strchr(game->map->cpy_map[i], 'P'))
		|| (ft_strchr(game->map->cpy_map[i], 'E')))
			return (false);
		i++;
	}
	return(true);
}
