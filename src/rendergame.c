/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendergame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:14:02 by ahentton          #+#    #+#             */
/*   Updated: 2024/09/04 10:01:12 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_wall(t_game *game, int y, int x)
{
	mlx_image_to_window(game->mlx, game->floor, x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->wall, x * TILE, y * TILE);
}

static void	render_exit(t_game *game, int y, int x)
{
	mlx_image_to_window(game->mlx, game->floor, x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->exit, x * TILE, y * TILE);
}

static void	render_player(t_game *game, int y, int x)
{
	mlx_image_to_window(game->mlx, game->floor, x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player, x * TILE, y * TILE);
	game->player_y = y;
	game->player_x = x;
}

static void	render_collectible(t_game *game, int y, int x)
{	
	mlx_image_to_window(game->mlx, game->floor, x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->collectible, x * TILE, y * TILE);
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
				render_wall(game, i, j);
			else if (game->map[i][j] == 'E')
				render_exit(game, i, j);
			else if (game->map[i][j] == 'C')
				render_collectible(game, i, j);
			else if (game->map[i][j] == 'P')
				render_player(game, i, j);
			else
				mlx_image_to_window(game->mlx, game->floor, j * TILE, i * TILE);
			j++;
		}
		i++;
	}
}
