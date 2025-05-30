/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-28 16:52:02 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-28 16:52:02 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fix_map(t_game *game)
{
	int		i;
	char	*temp;
	int		s_len;

	i = 0;
	while (game->map->map[i])
	{
		s_len = ft_strlen(game->map->map[i]);
		if (game->map->map[i][s_len - 1] == '\n')
		{
			temp = game->map->map[i];
			game->map->map[i] = ft_substr(temp, 0, s_len - 1);
			free(temp);
		}
		game->map->cpy_map[i] = ft_strdup(game->map->map[i]);
		i++;
	}
	game->map->cpy_map[i] = NULL;
	game->map->max_row = i;
	game->map->max_col = s_len;
}

void	save_items_loc(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	init_p_c(game, 'C');
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'C')
			{
				game->items[k].x = i;
				game->items[k].y = j;
				game->items[k].found = false;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	init_p_c(t_game *game, char c)
{
	t_player	*player;
	t_items		*items;

	if (c == 'P')
	{
		player = malloc(sizeof(t_player));
		if (!player)
			call_error(7, game);
		game->player = player;
	}
	if (c == 'C')
	{
		items = (t_items *) malloc(sizeof(t_items) * game->total_items);
		if (!items)
			call_error(7, game);
		game->items = items;
	}
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		perror("Failed to create struct");
		exit(1);
	}
	game->mlx_lib = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->player = NULL;
	game->items = NULL;
	game->found_items = 0;
	game->total_items = 0;
	return (game);
}

// void	init_mlx(t_game *game)
// {
// 	game->mlx_lib = mlx_init();
// 	if (!game->mlx_lib)
// 	{
// 		free_all(game);
// 		exit(1);
// 	}
// }
