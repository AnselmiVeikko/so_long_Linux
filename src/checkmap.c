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

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->y_index - 1 || j == 0 || j == game->x_index -1)
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

void	check_win(t_game *game, char *argv)
{
	int	i;
	char	**map;

	map = read_map(argv);
	fill_map(map, game->player_y, game->player_x);
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'C')
			|| ft_strchr(map[i], 'E'))
			error_exit("[ERROR]: Map is invalid! Props remain after fill!\n");
		i++;
	}
}
