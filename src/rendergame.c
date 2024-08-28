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

void	render_map(mlx_t *mlx, t_game *game, t_textures *texture)
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
				mlx_image_to_window(mlx, texture->wall, i, j);
			if (game->map[i][j] == 'E')
				mlx_image_to_window(mlx, texture->exit, i, j);
			if (game->map[i][j] == 'C')
				mlx_image_to_window(mlx, texture->collectible, i, j);
			if (game->map[i][j] == 'P')
				mlx_image_to_window(mlx, texture->player, i, j);
			else
				mlx_image_to_window(mlx, texture->floor, i, j);
			j++;
		}
		i++;
	}
}
