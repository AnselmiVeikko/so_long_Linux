/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:57:09 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/28 12:09:14 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(char *str)
{
	ft_printf("%s", str);
	exit (EXIT_FAILURE);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	while (i >= 0)
	{
		free (map[i]);
		i--;
	}
	free (map);
}

void	close_game(t_game *game)
{
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->floor);
	mlx_delete_image(game->mlx, game->player);
	mlx_delete_image(game->mlx, game->collectible);
	free_map (game->map);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit (EXIT_SUCCESS);
}
