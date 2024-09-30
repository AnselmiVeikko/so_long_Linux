/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:31:26 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/28 11:21:27 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*init_game(char *argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		error_exit("Error\nGame malloc has failed");
	game->map = split_map(argv);
	if (!game->map)
	{
		free(game);
		error_exit("Error\nMap file is invalid or empty!\n");
	}
	game->y_size = count_y(game->map);
	game->x_size = count_x(game->map);
	game->player_y = find_player_y(game->map);
	game->player_x = find_player_x(game->map);
	game->collect_count = count_prop(game->map, 'C');
	game->player_count = count_prop(game->map, 'P');
	game->exit_count = count_prop(game->map, 'E');
	game->move_counter = 0;
	return (game);
}
