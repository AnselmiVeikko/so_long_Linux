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
		error_exit("[ERROR]: Too many arguments! Only one argument expected.");
	if (argc < 2)
		error_exit("[ERROR]: Too few arguments! One argument expected.");
}

int	main(int argc, char *argv[])
{
	t_game		*game;
	t_textures	*texture;

	check_args(argc);
	check_mapname(argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		error_exit("[ERROR]: Game malloc has failed!");
	texture = malloc(sizeof(t_textures));
	if (!texture)
		error_exit("[ERROR]: Texture malloc has failed!");
	read_map(argv[1], game);
	validate_map(game);
	init_game(game);
	game->mlx = mlx_init(game->row * SI, game->index * SI, "Mordor42", false);
	init_textures(game, texture);
	render_map(game, texture);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	close_game(game, texture);
	return (0);
}
