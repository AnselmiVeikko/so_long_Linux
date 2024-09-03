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

void	init_game(t_game *game)
{
	game->row = count_row(game);
	game->index = count_index(game);
	game->player_count = 0;
	game->collect_count = count_collectibles(game);
	game->exit_count = 0;
	game->move_counter = 0;
	game->exit_game = 0;
	find_player(game, &game->player_y, &game->player_x);
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
}
