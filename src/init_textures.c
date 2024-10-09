/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:27:38 by ahentton          #+#    #+#             */
/*   Updated: 2024/09/30 13:27:49 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	mlx_image_t	*load_texture(mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		return (NULL);
	mlx_delete_texture(texture);
	return (img);
}

void	init_textures(t_game *game)
{
	game->wall = load_texture(game->mlx, "textures/Wall.png");
	if (!game->wall)
		close_game(game);
	game->exit = load_texture(game->mlx, "textures/Exit.png");
	if (!game->exit)
		close_game(game);
	game->floor = load_texture(game->mlx, "textures/Floor.png");
	if (!game->floor)
		close_game(game);
	game->player = load_texture(game->mlx, "textures/Player.png");
	if (!game->player)
		close_game(game);
	game->collectible = load_texture(game->mlx, "textures/Collectible.png");
	if (!game->collectible)
		close_game(game);
}
