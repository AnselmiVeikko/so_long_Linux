/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:31:26 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/27 09:31:29 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void  init_game(t_game *game)
{
  game->row = 0;
  game->colum = 0;
  game->move_x = 0;
  game->move_y = 0;
  game->player_count = 0;
  game->collect_count = 0;
  game->move_count = 0;
  game->exit_count = 0;
  game->exit_game = 0;
  game->locate_player_x = 0;
  game->locate_player_y = 0;
}

void  init_textures(t_game *game)
{
  game->temp = mlx_load_png("../assets/Exit.png");
  game->exit = mlx_texture_to_image(game->mlx, game->temp);
  mlx_delete_texture(game->temp);
  game->temp = mlx_load_png("../assets/Wall.png");
  game->wall = mlx_texture_to_image(game->mlx, game->temp);
  mlx_delete_texture(game->temp);
  game->temp = mlx_load_png("../assets/Floor.png");
  game->floor = mlx_texture_to_image(game->mlx, game->temp);
  mlx_delete_texture(game->temp);
  game->temp = mlx_load_png("../assets/Player.png");
  game->player = mlx_texture_to_image(game->mlx, game->temp);
  mlx_delete_texture(game->temp);
  game->temp = mlx_load_png("../assets/Collectible.png");
  game->collectible = mlx_texture_to_image(game->mlx, game->temp);
}
