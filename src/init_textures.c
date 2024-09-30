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
	mlx_texture_t	*temp;
	mlx_image_t		*prop;

	temp = mlx_load_png(path);
	prop = mlx_texture_to_image(mlx, temp);
	mlx_delete_texture(temp);
	return (prop);
}

void	init_textures(t_game *game)
{
	game->wall = load_texture(game->mlx, "assets/Wall.png");
	game->exit = load_texture(game->mlx, "assets/Exit.png");
	game->floor = load_texture(game->mlx, "assets/Floor.png");
	game->player = load_texture(game->mlx, "assets/Player.png");
	game->collectible = load_texture(game->mlx, "assets/Collectible.png");
}
