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

void	render_player(t_game *game, char c, int x, int y)
{
	if (c == 'A')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs->p_left,y * 32, x * 32);
	if (c == 'W')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs->p_up,y * 32, x * 32);
	if (c == 'D')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs->p_right,y * 32, x * 32);
	if (c == 'S')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs->p_down,y * 32, x * 32);
}

void	render_map(t_game *game, char c)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->max_row)
	{
		y = 0;
		while (y < game->map->max_col)
		{
			if (game->map->map[x][y] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs->bg,y * 32, x * 32);
			else if (game->map->map[x][y] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs->wall,y * 32, x * 32);
			else if (game->map->map[x][y] == 'P')
				render_player(game, c, x, y);
			else if (game->map->map[x][y] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs->collec,y * 32, x * 32);
			else if (game->map->map[x][y] == 'E' )
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs->exit_closed,y * 32, x * 32);
			else if (game->map->map[x][y] == 'X')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs->p_on_exit,y * 32, x * 32);
			y++;
		}
		x++;
	}
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
	mlx_hook(game->mlx_win, 2, 1L << 0, hook_handler, game);
	mlx_loop(game->mlx);
	free_all(game, 0);
	return (0);
}
