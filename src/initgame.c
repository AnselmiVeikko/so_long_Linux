/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:31:26 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/28 11:21:27 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_game *game, char *argv)
{
	game->map = read_map(argv);
	game->y_size = init_y(game);
	game->x_size = init_x(game);
	count_props(game);
	game->move_counter = 0;
	game->exit_game = 0;
	game->player_y = find_player_y(game);
	game->player_x = find_player_x(game);
}

void	init_textures(t_game *game)
{
	game->temp = mlx_load_png("assets/Exit.png");
	game->exit = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
	game->temp = mlx_load_png("assets/Wall.png");
	game->wall = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
	game->temp = mlx_load_png("assets/Floor.png");
	game->floor = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
	game->temp = mlx_load_png("assets/Player.png");
	game->player = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
	game->temp = mlx_load_png("assets/Collectible.png");
	game->collectible = mlx_texture_to_image(game->mlx, game->temp);
	mlx_delete_texture(game->temp);
}
