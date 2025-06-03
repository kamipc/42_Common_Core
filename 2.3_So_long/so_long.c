/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 13:55:48 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-18 13:55:48 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_game *g, char c, int x, int y)
{
	if (c == 'A')
		mlx_put_image_to_window(g->mlx, g->win, g->imgs->p_a, (y * 32) - g->cx,
			(x * 32) - g->cy);
	if (c == 'W')
		mlx_put_image_to_window(g->mlx, g->win, g->imgs->p_w, (y * 32) - g->cx,
			(x * 32) - g->cy);
	if (c == 'D')
		mlx_put_image_to_window(g->mlx, g->win, g->imgs->p_d, (y * 32) - g->cx,
			(x * 32) - g->cy);
	if (c == 'S')
		mlx_put_image_to_window(g->mlx, g->win, g->imgs->p_s, (y * 32) - g->cx,
			(x * 32) - g->cy);
}

void	render_node(t_game *g, char c, int x, int y)
{
	if (g->map->map[x][y] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->imgs->wall,
			(y * 32) - g->cx, (x * 32) - g->cy);
	else if (g->map->map[x][y] == 'P')
		render_player(g, c, x, y);
	else if (g->map->map[x][y] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->imgs->item,
			(y * 32) - g->cx, (x * 32) - g->cy);
	else if (g->map->map[x][y] == 'E' && (g->found_items != g->total_items))
		mlx_put_image_to_window(g->mlx, g->win, g->imgs->exitc,
			(y * 32) - g->cx, (x * 32) - g->cy);
	else if (g->map->map[x][y] == 'E' && (g->found_items == g->total_items))
		mlx_put_image_to_window(g->mlx, g->win, g->imgs->exito,
			(y * 32) - g->cx, (x * 32) - g->cy);
	else if (g->map->map[x][y] == 'X')
		mlx_put_image_to_window(g->mlx, g->win, g->imgs->pone,
			(y * 32) - g->cx, (x * 32) - g->cy);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->imgs->bg, (y * 32) - g->cx,
			(x * 32) - g->cy);
}

void	render_map(t_game *g, char c)
{
	int	x;
	int	y;

	x = -0;
	get_cam_pos(g);
	while (x < g->map->max_row)
	{
		y = 0;
		while (y < g->map->max_col)
		{
			render_node(g, c, x, y);
			y++;
		}
		x++;
	}
}

int	close_game(t_game *game)
{
	free_all(game, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		perror("Invalid argument");
		exit(1);
	}
	validade_map_file(av[1]);
	game = init_game();
	read_map(av[1], game);
	check_valid_map(game);
	init_mlx(game);
	mlx_hook(game->win, 2, 1L << 0, hook_handler, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	free_all(game, 0);
	return (0);
}
