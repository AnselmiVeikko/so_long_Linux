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
	game->row = 0;
	game->index = 0;
	game->move_x = 0;
	game->move_y = 0;
	game->player_count = 0;
	game->collect_count = 0;
	game->exit_count = 0;
	game->move_counter = 0;
	game->exit_game = 0;
	game->player_x = 0;
	game->player_y = 0;
}

void	init_textures(t_game *game, t_textures *texture)
{
	texture->temp = mlx_load_png("../assets/Exit.png");
	texture->exit = mlx_texture_to_image(game->mlx, texture->temp);
	mlx_delete_texture(texture->temp);
	texture->temp = mlx_load_png("../assets/Wall.png");
	texture->wall = mlx_texture_to_image(game->mlx, texture->temp);
	mlx_delete_texture(texture->temp);
	texture->temp = mlx_load_png("../assets/Floor.png");
	texture->floor = mlx_texture_to_image(game->mlx, texture->temp);
	mlx_delete_texture(texture->temp);
	texture->temp = mlx_load_png("../assets/Player.png");
	texture->player = mlx_texture_to_image(game->mlx, texture->temp);
	mlx_delete_texture(texture->temp);
	texture->temp = mlx_load_png("../assets/Collectible.png");
	texture->collectible = mlx_texture_to_image(game->mlx, texture->temp);
}
