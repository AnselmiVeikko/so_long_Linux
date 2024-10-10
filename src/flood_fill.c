/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:49:08 by ahentton          #+#    #+#             */
/*   Updated: 2024/10/10 10:49:10 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	fill_map_collectibles(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'E')
		return ;
	map[y][x] = 'X';
	fill_map_collectibles(map, y - 1, x);
	fill_map_collectibles(map, y + 1, x);
	fill_map_collectibles(map, y, x - 1);
	fill_map_collectibles(map, y, x + 1);
}

static	void	fill_map_exit(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	fill_map_exit(map, y - 1, x);
	fill_map_exit(map, y + 1, x);
	fill_map_exit(map, y, x - 1);
	fill_map_exit(map, y, x + 1);
}

void	check_fill_collectibles(t_game *game, char *argv)
{
	int		i;
	char	**map;

	map = split_map(argv);
	if (!map)
	{
		free_game(game);
		error_exit("Error\nWhat happened to the map?!");
	}
	fill_map_collectibles(map, game->player_y, game->player_x);
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'C'))
		{
			free_game(game);
			free_map(map);
			error_exit("Error\nMap is invalid! Props remain after fill!\n");
		}
		i++;
	}
	free_map (map);
}

void	check_fill_exit(t_game *game, char *argv)
{
	int		i;
	char	**map;

	map = split_map(argv);
	if (!map)
	{
		free_game(game);
		error_exit("Error\nWhat happened to the map?!");
	}
	fill_map_exit(map, game->player_y, game->player_x);
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'E'))
		{
			free_game(game);
			free_map(map);
			error_exit("Error\nMap is invalid! Props remain after fill!\n");
		}
		i++;
	}
	free_map (map);
}
