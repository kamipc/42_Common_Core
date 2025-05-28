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
	while (game->map[i])
	{
		s_len = ft_strlen(game->map[i]);
		if (game->map[i][s_len - 1] == '\n')
		{
			temp = (char *) malloc (s_len);
			if (!temp)
				call_error(0, game);
			temp = game->map[i];
			game->map[i] = ft_substr(temp, 0, s_len - 1);
			free(temp);
		}
		i++;
	}
}

void	read_map(char *map_loc, t_game *game)
{
	int		map_fd;
	char	*line;
	int		i;

	i = 0;
	map_fd = open(map_loc, O_RDONLY);
	if (map_fd == -1)
		call_error(0, game);
	while ((line = get_next_line(map_fd)) != NULL)
	{
		i++;
		free(line);
	}
	close(map_fd);
	game->map = (char **)malloc((i + 1) * (sizeof(char *)));
	map_fd = open(map_loc, O_RDONLY);
	if (map_fd == -1)
		call_error(1, game);
	i = 0;
	while ((game->map[i] = get_next_line(map_fd))!= NULL)
		i++;
	game->map[i] = NULL;
	close(map_fd);
}

void	save_items_loc(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	init_p_c(game, 'C');
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
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