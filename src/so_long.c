/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:00:11 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/28 11:23:32 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_args(int argc)
{
	if (argc > 2)
	{
		ft_printf("[ERROR]: Too many arguments! Only one argument expected.");
		exit (EXIT_FAILURE);
	}
	if (argc < 2)
	{
		ft_printf("[ERROR]: Too few arguments! One argument expected.");
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_game		*game;
	t_textures	*texture;

	check_args(argc);
	check_mapname(argv[1]);
	init_game(game);
	init_textures(game, texture);
	read_map(argv[1], game);
	find_player(game, game->player_y, game->player_x);
	fill_map(game, game->player_y, game->player_x);
	validate_map(game);
	render_map(game->mlx, game, texture);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
