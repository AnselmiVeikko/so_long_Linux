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
		error_exit("Error\nMLX42: texture fail");
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error_exit("Error\nMLX42: img fail");
	mlx_delete_texture(texture);
	return (img);
}

void	init_textures(t_game *game)
{
	game->wall = load_texture(game->mlx, "textures/Wall.png");
	game->exit = load_texture(game->mlx, "textures/Exit.png");
	game->floor = load_texture(game->mlx, "textures/Floor.png");
	game->player = load_texture(game->mlx, "textures/Player.png");
	game->collectible = load_texture(game->mlx, "textures/Collectible.png");
}
