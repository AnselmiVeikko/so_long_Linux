/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:12:36 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/23 12:46:50 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!ft_strchr("1PCE0", game->map[i][j]))
			{
				free_map(game->map);
				error_exit("[MAP ERROR]: Invalid characters in the map file!");
			}
			j++;
		}
		i++;
	}
}

void	validate_map(t_game *game, char *argv)
{
	check_map(game);
	check_props(game);
	check_borders(game);
	check_shape(game);
	check_win(game, argv);
}
