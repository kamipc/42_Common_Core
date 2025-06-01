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

void	init_player(t_game *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		call_error(7, game);
	game->player = player;
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
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->player = NULL;
	game->found_items = 0;
	game->total_items = 0;
	game->imgs = NULL;
	game->move_count = 0;
	return (game);
}
void	init_imgs(t_game *game)
{
	t_imgs	*imgs;

	imgs = malloc(sizeof(t_imgs));
	if (!game)
		call_error(7, game);
	imgs->h = game->map->max_row * 32;
	imgs->w = game->map->max_col * 32;
	imgs->bg = mlx_xpm_file_to_image(game->mlx, "assets/bg.xpm", &imgs->w, &imgs->h);
	imgs->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &imgs->w, &imgs->h);
	imgs->p_down = mlx_xpm_file_to_image(game->mlx, "assets/p_down.xpm", &imgs->w, &imgs->h);
	imgs->p_left = mlx_xpm_file_to_image(game->mlx, "assets/p_left.xpm", &imgs->w, &imgs->h);
	imgs->p_right = mlx_xpm_file_to_image(game->mlx, "assets/p_right.xpm", &imgs->w, &imgs->h);
	imgs->p_up = mlx_xpm_file_to_image(game->mlx, "assets/p_up.xpm", &imgs->w, &imgs->h);
	imgs->collec = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &imgs->w, &imgs->h);
	imgs->exit_closed = mlx_xpm_file_to_image(game->mlx, "assets/exit_closed.xpm", &imgs->w, &imgs->h);
	imgs->exit_open = mlx_xpm_file_to_image(game->mlx, "assets/exit_open.xpm", &imgs->w, &imgs->h);
	imgs->p_on_exit = mlx_xpm_file_to_image(game->mlx, "assets/p_on_exit.xpm", &imgs->w, &imgs->h);
	if (!(imgs->bg) || !(imgs->collec) || !(imgs->exit_closed) || !(imgs->exit_open)
		|| !(imgs->p_down) || !(imgs->p_left) || !(imgs->p_right) || !(imgs->p_up)
		|| !(imgs->wall) || !(imgs->p_on_exit))
		call_error(8, game);
	game->imgs = imgs;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		call_error(9, game);
	init_imgs(game);
	game->mlx_win = mlx_new_window(game->mlx, game->map->max_col * 32, game->map->max_row * 32, "So_long");
	if (!game->mlx_win)
		call_error(9, game);
	render_map(game, 'D');
}
