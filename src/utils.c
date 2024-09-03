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

void	close_game(t_game *game)
{
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->floor);
	mlx_delete_image(game->mlx, game->player);
	mlx_delete_image(game->mlx, game->collectible);
	free_map (game->mapcopy);
	free_map (game->map);
	free (game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit (EXIT_SUCCESS);
}

int	count_row(t_game *game)
{
	int	row;

	row = 0;
	while (game->map[row])
		row++;
	return (row);
}

int	count_index(t_game *game)
{
	int index;
	
	index = 0;
	while (game->map[1][index])
		index++;
	return (index);
}

int	count_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	collectibles;

	i = 0;
	j = 0;
	collectibles = 0;

	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	return (collectibles);
}
