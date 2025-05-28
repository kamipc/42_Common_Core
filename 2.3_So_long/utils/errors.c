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
	if (error_type == 0 || error_type == 1)
	{
		perror("Failed to open map file");
		exit(1);
	}
	if (error_type == 1)
		perror("Failed to open map file");
	if (error_type == 2)
		perror("Map not fully surrounded by walls");
	if (error_type == 3)
		perror("Invalid number of Players on map");
	if (error_type == 4)
		perror("Invalid number of Exits on map");
	if (error_type == 5)
		perror("There are no collectibles on the map");
	if (error_type == 6)
		perror("Invalid map dimensions");
	if (error_type == 7)
		perror("Failed to allocate memory");
	free_map(game);
	exit(1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
