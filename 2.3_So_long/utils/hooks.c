/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-01 14:32:25 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-06-01 14:32:25 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	hook_handler(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_all(game, 0);
	if (game->move_count == 0)
		ft_printf("%i\n", game->move_count);
	if (keycode == 97 || keycode == 65361)
		move_left(game);
	if (keycode == 119 || keycode == 65362)
		move_up(game);
	if (keycode == 100 || keycode == 65363)
		move_right(game);
	if (keycode == 115 || keycode == 65364)
		move_down(game);
	return (0);
}

void	move_left(t_game *game)
{
	if (game->map->map[game->player->x][game->player->y - 1] != '1')
	{
		game->move_count++;
		ft_printf("%i\n", game->move_count);
		if (game->map->map[game->player->x][game->player->y] == 'X')
				game->map->map[game->player->x][game->player->y] = 'E';
		else 
			game->map->map[game->player->x][game->player->y] = '0';
		if (game->map->map[game->player->x][game->player->y - 1] == 'C')
		{
			game->map->map[game->player->x][game->player->y - 1] = 'P';
			game->found_items++;
		}
		else if (game->map->map[game->player->x][game->player->y - 1] == 'E' && game->found_items != game->total_items)
			game->map->map[game->player->x][game->player->y - 1] = 'X';
		else if (game->map->map[game->player->x][game->player->y - 1] == 'E' && game->found_items == game->total_items)
			free_all(game, 0);
		else
			game->map->map[game->player->x][game->player->y - 1] = 'P';
		game->player->y -= 1;
		render_map(game, 'A');
	}
}

void	move_up(t_game *game)
{
	if (game->map->map[game->player->x - 1][game->player->y] != '1')
	{
		game->move_count++;
		ft_printf("%i\n", game->move_count);
		if (game->map->map[game->player->x][game->player->y] == 'X')
				game->map->map[game->player->x][game->player->y] = 'E';
		else 
			game->map->map[game->player->x][game->player->y] = '0';
		if (game->map->map[game->player->x - 1][game->player->y] == 'C')
		{
			game->map->map[game->player->x - 1][game->player->y] = 'P';
			game->found_items++;
		}
		else if (game->map->map[game->player->x - 1][game->player->y] == 'E' && game->found_items != game->total_items)
			game->map->map[game->player->x - 1][game->player->y] = 'X';
		else if (game->map->map[game->player->x - 1][game->player->y] == 'E' && game->found_items == game->total_items)
			free_all(game, 0);
		else
			game->map->map[game->player->x - 1][game->player->y] = 'P';
		game->player->x -= 1;
		render_map(game, 'W');
	}
}

void	move_right(t_game *game)
{
	if (game->map->map[game->player->x][game->player->y + 1] != '1')
	{
		game->move_count++;
		ft_printf("%i\n", game->move_count);
		if (game->map->map[game->player->x][game->player->y] == 'X')
				game->map->map[game->player->x][game->player->y] = 'E';
		else 
			game->map->map[game->player->x][game->player->y] = '0';
		if (game->map->map[game->player->x][game->player->y + 1] == 'C')
		{
			game->map->map[game->player->x][game->player->y + 1] = 'P';
			game->found_items++;
		}
		else if (game->map->map[game->player->x][game->player->y + 1] == 'E' && game->found_items != game->total_items)
			game->map->map[game->player->x][game->player->y + 1] = 'X';
		else if (game->map->map[game->player->x][game->player->y + 1] == 'E' && game->found_items == game->total_items)
			free_all(game, 0);
		else
			game->map->map[game->player->x][game->player->y + 1] = 'P';
		game->player->y += 1;
		render_map(game, 'D');
	}
}

void	move_down(t_game *game)
{
	if (game->map->map[game->player->x + 1][game->player->y] != '1')
	{
		game->move_count++;
		ft_printf("%i\n", game->move_count);
		if (game->map->map[game->player->x][game->player->y] == 'X')
				game->map->map[game->player->x][game->player->y] = 'E';
		else 
			game->map->map[game->player->x][game->player->y] = '0';
		if (game->map->map[game->player->x + 1][game->player->y] == 'C')
		{
			game->map->map[game->player->x + 1][game->player->y] = 'P';
			game->found_items++;
		}
		else if (game->map->map[game->player->x + 1][game->player->y] == 'E' && game->found_items != game->total_items)
			game->map->map[game->player->x + 1][game->player->y] = 'X';
		else if (game->map->map[game->player->x + 1][game->player->y] == 'E' && game->found_items == game->total_items)
			free_all(game, 0);
		else
			game->map->map[game->player->x + 1][game->player->y] = 'P';
		game->player->x += 1;
		render_map(game, 'S');
	}
}