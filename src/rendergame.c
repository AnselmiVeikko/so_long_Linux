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

void	render_walls(t_game *game, int row, int index)
{
	mlx_image_to_window(game->mlx, game->floor, index * SI, row * SI);
	mlx_image_to_window(game->mlx, game->wall, index * SI, row * SI);
}

void	render_exit(t_game *game, int row, int index)
{
	mlx_image_to_window(game->mlx, game->floor, index * SI, row * SI);
	mlx_image_to_window(game->mlx, game->exit, index * SI, row * SI);
}

void	render_player(t_game *game, int row, int index)
{
	mlx_image_to_window(game->mlx, game->floor, index * SI, row * SI);
	mlx_image_to_window(game->mlx, game->player, index * SI, row * SI);
	game->player_y = row;
	game->player_x = index;
}

void	render_collectibles(t_game *game, int row, int index)
{	
	mlx_image_to_window(game->mlx, game->floor, index * SI, row * SI);
	mlx_image_to_window(game->mlx, game->collectible, index * SI, row * SI);
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
				render_walls(game, i, j);
			else if (game->map[i][j] == 'E')
				render_exit(game, i, j);
			else if (game->map[i][j] == 'C')
				render_collectibles(game, i, j);
			else if (game->map[i][j] == 'P')
				render_player(game, i, j);
			else
				mlx_image_to_window(game->mlx, game->floor, j * SI, i * SI);
			j++;
		}
		i++;
	}
}
