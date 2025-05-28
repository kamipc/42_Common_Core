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
	if (ac != 2)
	{
		perror("Invalid argument");
		exit(1);
	}
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if (!game)
	{
		perror("Error\n");
		return (1);
	}
	read_map(av[1], game);
	fix_map(game);
	check_valid_map(game);
	free_map(game);
	return (0);
}
