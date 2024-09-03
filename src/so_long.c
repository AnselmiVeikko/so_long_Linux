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

	check_args(argc);
	check_mapname(argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		error_exit("[ERROR]: Game malloc has failed!");
	read_map(argv[1], game);
	validate_map(game);
	init_game(game);
	ft_printf("[ROW]:%d, [INDEX]:%d\n", game->row, game->index);
	game->mlx = mlx_init(game->index * SI, game->row * SI, "Mordor42", false);
	init_textures(game);
	render_map(game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)close_window, game);
	mlx_loop(game->mlx);
	close_game(game);
	return (0);
}
