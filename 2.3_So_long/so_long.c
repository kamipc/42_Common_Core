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
	// init_mlx(game);
	free_all(game);
	return (0);
}
