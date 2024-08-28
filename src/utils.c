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

void	delete_textures(t_game *game, t_textures *texture)
{
	mlx_delete_image(game->mlx, texture->wall);
	mlx_delete_image(game->mlx, texture->floor);
	mlx_delete_image(game->mlx, texture->player);
	mlx_delete_image(game->mlx, texture->collectible);
	mlx_delete_image(game->mlx, texture->exit);
}

void	close_game(t_game *game, t_textures *texture)
{
	delete_textures(game, texture);
	free (game);
	mlx_close_window(game->mlx);
}
