/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 18:21:01 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-18 18:21:01 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	call_error(int error_type, t_game *game)
{
	ft_printf("Error\n");
	if (error_type == 0)
		perror("Failed to open map file");
	if (error_type == 2)
		perror("Map not fully surrounded by walls");
	if (error_type == 3)
		perror("Invalid number of Exits on map");
	if (error_type == 4)
		perror("Invalid number of Players on map");
	if (error_type == 5)
		perror("There are no collectibles on the map");
	if (error_type == 6)
		perror("Invalid map dimensions");
	if (error_type == 7)
		perror("Failed to allocate memory");
	if (error_type == 1)
		perror("Map impossible to complete");
	if (error_type == 8)
		perror("Failed to load images");
	if (error_type == 9)
		perror("Failed to initialize minilibX");
	free_all(game, 1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[i])
	{
		free(game->map->map[i]);
		free(game->map->cpy_map[i]);
		i++;
	}
	i = 0;
	free(game->map->map);
	free(game->map->cpy_map);
	free(game->map);
}
void	free_imgs(t_game *game)
{
	if (game->imgs->bg)
		mlx_destroy_image(game->mlx, game->imgs->bg);
	if (game->imgs->collec)
		mlx_destroy_image(game->mlx, game->imgs->collec);
	if (game->imgs->exit_closed)
		mlx_destroy_image(game->mlx, game->imgs->exit_closed);
	if (game->imgs->exit_open)
		mlx_destroy_image(game->mlx, game->imgs->exit_open);
	if (game->imgs->p_down)
		mlx_destroy_image(game->mlx, game->imgs->p_down);
	if (game->imgs->p_left)
		mlx_destroy_image(game->mlx, game->imgs->p_left);
	if (game->imgs->p_right)
		mlx_destroy_image(game->mlx, game->imgs->p_right);
	if (game->imgs->p_up)
		mlx_destroy_image(game->mlx, game->imgs->p_up);
	if (game->imgs->wall)
		mlx_destroy_image(game->mlx, game->imgs->wall);
	if (game->imgs->p_on_exit)
		mlx_destroy_image(game->mlx, game->imgs->p_on_exit);
}

void	free_all(t_game *game, int status)
{
	if (game->map)
		free_map(game);
	if (game->player)
		free(game->player);
	if (game->imgs)
	{
		free_imgs(game);
		free(game->imgs);
		game->imgs = NULL;
	}
	if (game->mlx_win)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		game->mlx_win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game)
		free(game);
	exit(status);
}
