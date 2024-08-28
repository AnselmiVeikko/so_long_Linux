/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendergame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:14:02 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/28 11:22:46 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_walls(mlx_t *mlx, int row, int index, t_textures *texture)
{
	mlx_image_to_window(mlx, texture->floor, index * SI, row * SI);
	mlx_image_to_window(mlx, texture->wall, index * SI, row * SI);
}

void	render_exit(mlx_t *mlx, int row, int index, t_textures *texture)
{
	mlx_image_to_window(mlx, texture->floor, index * SI, row * SI);
	mlx_image_to_window(mlx, texture->exit, index * SI, row * SI);
}

void	render_player(mlx_t *mlx, int row, int index, t_textures *texture)
{
	
	mlx_image_to_window(mlx, texture->floor, index * SI, row * SI);
	mlx_image_to_window(mlx, texture->player, index * SI, row * SI);
}

void	render_collectibles(mlx_t *mlx, int row, int index, t_textures *texture)
{	
	mlx_image_to_window(mlx, texture->floor, index * SI, row * SI);
	mlx_image_to_window(mlx, texture->collectible, index * SI, row * SI);
}

void	render_map(t_game *game, t_textures *texture)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				render_walls(game->mlx, i, j, texture);
			if (game->map[i][j] == 'E')
				render_exit(game->mlx, i, j, texture);
			if (game->map[i][j] == 'C')
				render_collectibles(game->mlx, i, j, texture);
			if (game->map[i][j] == 'P')
				render_player(game->mlx, i, j, texture);
			else
				mlx_image_to_window(game->mlx, texture->floor, j * SI, i * SI);
			j++;
		}
		i++;
	}
}
