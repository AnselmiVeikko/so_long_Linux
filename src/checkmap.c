/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:19:41 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/28 11:21:16 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_mapname(char *mapname)
{
	size_t	name_len;

	name_len = ft_strlen(mapname);
	if (!ft_strnstr(&mapname[name_len - 4], ".ber", 5))
		error_exit("[ERROR]: Map name is invalid!");
}

void	check_props(t_game *game)
{
	if (game->player_count != 1)
		error_exit("[MAP ERROR]: Invalid amount of player characters!\n");
	if (game->exit_count != 1)
		error_exit("[MAP ERROR]: Invalid amount of exits!\n");
	if (game->collect_count < 1)
		error_exit("[MAP ERROR]: Invalid amount of collectibles!\n");
}

void	check_borders(t_game *game)
{
	int	i;
	int	j;

	while (game->map[game->row])
	{
		while (game->map[game->row][game->index])
			game->index++;
		game->row++;
	}
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->row - 1 || j == 0 || j == game->index -1)
			{
				if (game->map[i][j] != '1')
					error_exit("[MAP ERROR]: Invalid map borders!\n");
			}
			j++;
		}
		i++;
	}
}

void	check_shape(t_game *game)
{
	size_t	row_len;
	int		i;

	row_len = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		if (row_len != ft_strlen(game->map[i]))
			error_exit("[MAP ERROR]: Map is not rectangular... seriously?\n");
		i++;
	}
}

void	check_win(t_game *game)
{
	int	i;
	int	player_row;
	int	player_index;

	player_row = 0;
	player_index = 0;
	find_player(game, &player_row, &player_index);
	fill_map(game, player_row, player_index);
	i = 0;
	while (game->mapcopy[i])
	{
		if (ft_strchr(game->mapcopy[i], 'C')
			|| ft_strchr(game->mapcopy[i], 'E'))
			error_exit("[ERROR]: Map is invalid! Props remain after fill!\n");
		i++;
	}
}
