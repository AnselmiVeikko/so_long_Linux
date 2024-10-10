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
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free (map);
}

void	free_game(t_game *game)
{
	free_map(game->map);
	free(game);
}

int	ft_notchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (1);
		i++;
	}
	return (0);
}

void	close_game(t_game *game)
{
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->floor);
	mlx_delete_image(game->mlx, game->player);
	mlx_delete_image(game->mlx, game->collectible);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game);
	exit (EXIT_SUCCESS);
}
