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

void	free_game(t_game *game, t_textures *texture)
{
	mlx_delete_image(game->mlx, texture->exit);
	mlx_delete_image(game->mlx, texture->wall);
	mlx_delete_image(game->mlx, texture->floor);
	mlx_delete_image(game->mlx, texture->player);
	mlx_delete_image(game->mlx, texture->collectible);
	free(game->map);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit (EXIT_SUCCESS);
}
/*
void	close_game(t_game *game, t_textures *texture)
{
	delete_textures(game, texture);
	free (game->map);
	mlx_close_window(game->mlx);
	exit (EXIT_SUCCESS);
}*/

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
