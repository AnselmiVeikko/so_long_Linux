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
	int	error;

	error = 0;
	if (game->player_count != 1)
		error = 1;
	if (game->exit_count != 1)
		error = 1;
	if (game->collect_count < 1)
		error = 1;
	if (error == 1)
	{
		free_map(game->map);
		error_exit("[MAP ERROR]: Invalid amount of props/players!\n");
	}
}

void	check_borders(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->y_size - 1 
				|| j == 0 || j == game->x_size - 1)
				if (game->map[i][j] != '1')
				{
					free_map(game->map);
					error_exit("[MAP ERROR]: Invalid borders!\n");
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

	i = 0;
	row_len = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if (row_len != ft_strlen(game->map[i]))
		{
			free_map(game->map);
			error_exit("[MAP ERROR]: Map is not rectangular... seriously?\n");
		}
		i++;
	}
}

void	check_win(t_game *game, char *argv)
{
	int		i;
	char	**map;

	map = read_map(argv);
	fill_map(map, game->player_y, game->player_x);
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'C')
			|| ft_strchr(map[i], 'E'))
		{
			free_map(game->map);
			free_map(map);
			error_exit("[ERROR]: Map is invalid! Props remain after fill!\n");
		}
		i++;
	}
	free_map (map);
}
