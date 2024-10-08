/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:12:36 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/23 12:46:50 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	check_props(t_game *game)
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
		free_game(game);
		error_exit("Error\nInvalid amount of props/players!\n");
	}
}

static	void	check_borders(t_game *game)
{
	int	i;
	int	error;
	int	y_last;
	int	x_last;

	i = 0;
	error = 0;
	y_last = game->y_size - 1;
	x_last = game->x_size - 1;
	while (game->map[i])
	{
		if ((i == 0 || i == y_last) && ft_notchar(game->map[i], '1'))
			error = 1;
		else if (game->map[i][0] != '1' || game->map[i][x_last] != '1')
			error = 1;
		i++;
	}
	if (error == 1)
	{
		free_game(game);
		error_exit("Error\nInvalid map borders!\n");
	}
}

static	void	check_shape(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[i]))
		{
			free_game(game);
			error_exit("Error\nMap is not rectangular... seriously?\n");
		}
		i++;
	}
}

void	check_map(t_game *game, char *argv)
{
	check_shape(game);
	check_borders(game);
	check_props(game);
	check_fill_collectibles(game, argv);
	check_fill_exit(game, argv);
}
