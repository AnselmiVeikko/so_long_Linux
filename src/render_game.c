/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:14:02 by ahentton          #+#    #+#             */
/*   Updated: 2024/09/04 10:01:12 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	render_prop(t_game *game, mlx_image_t *img, int y, int x)
{
	mlx_image_to_window(game->mlx, game->floor, x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, img, x * TILE, y * TILE);
	if (img == game->player)
	{
		game->player_y = y;
		game->player_x = x;
	}
}

void	render_map(t_game *game)
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
				render_prop(game, game->wall, i, j);
			else if (game->map[i][j] == 'E')
				render_prop(game, game->exit, i, j);
			else if (game->map[i][j] == 'C')
				render_prop(game, game->collectible, i, j);
			else if (game->map[i][j] == 'P')
				render_prop(game, game->player, i, j);
			else
				mlx_image_to_window(game->mlx, game->floor, j * TILE, i * TILE);
			j++;
		}
		i++;
	}
}
