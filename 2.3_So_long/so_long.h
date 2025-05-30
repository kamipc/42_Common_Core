/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 13:55:36 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-18 13:55:36 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_items
{
	int		x;
	int		y;
	bool	found;
}				t_items;

typedef struct s_map
{
	char	**map;
	char	**cpy_map;
	int		max_row;
	int		max_col;
}				t_map;

typedef struct s_game
{
	void		*mlx_lib;
	void		*mlx_win;
	t_player	*player;
	t_items		*items;
	int			total_items;
	int			found_items;
	t_map		*map;
}				t_game;

//inits
t_game	*init_game(void);
void	init_p_c(t_game *game, char c);
void	read_map(char *map_loc, t_game *game);
void	save_items_loc(t_game *game);
void	fix_map(t_game *game);

// validade map
void	validade_map_file(char	*map_loc);
void	check_valid_map(t_game *game);
bool	wall_check(char **map);
bool	player_check(t_game *game);
bool	exit_check(char **map);
bool	items_check(t_game *game);
bool	map_is_ret_check(char **map);
bool	map_impossible(t_game *game);

//handle errors and frees
void	call_error(int error_type, t_game *game);
void	free_map(t_game *game);
void	free_all(t_game *game);

#endif