/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:19:41 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/23 13:03:58 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_name(char *mapname)
{
	int	name_len;

	name_len = ft_strlen(mapname);
	if (!ft_strnstr(mapname[name_len - 4], ".ber", 5))
	{
		ft_printf("[ERROR]: Map name is invalid!");
		exit (EXIT_FAILURE);
	}
}

void	check_props(t_game *game)
{
	if (game->player_count != 1)
	{
		ft_printf("[MAP ERROR]: Invalid amount of player characters!\n");
		exit (EXIT_FAILURE);
	}
	if (game->exit_count != 1)
	{
		ft_printf("[MAP ERROR]: Invalid amount of exits!\n");
		exit (EXIT_FAILURE);
	}
	if (game->collect_count < 1)
	{
		ft_printf("[MAP ERROR]: Invalid amount of collectibles!\n");
		exit (EXIT_FAILURE);
	}
}

void	check_borders(t_game *game)
{
	int	i;
	int	j;

	while (game->row)
	{
		while (game->colum)
			game->colum++;
		game->row++;
	}
	i = 0;
	while (game->map[i++])
	{
		j = 0;
		while (game->map[i][j++])
		{
			if (i == 0 || i == game->row - 1 || x == 0 || x == game->colum -1)
			{
				if (game->map[i][j] != '1')
				{
					ft_printf("[MAP ERROR]: Invalid map borders!\n");
					exit (EXIT_FAILURE);
				}
			}
		}
	}
}

void	check_shape(t_game *game)
{
	int	row_len;
	int	i;

	row_len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (row_len != ft_strlen(game->map[i]))
		{
			ft_printf("[MAP ERROR]: Map is not rectangular... seriously?\n");
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void	check_win(t_game *game)
{
	int	i;
	int	player_row;
	int	player_col;

	player_row = 0;
	player_col = 0;
	find_player(game, &player_row, &player_col);
	fill_map(game, player_row, player_col);
	i = 0;
	while (game->mapcopy[i])
	{
		if (ft_strchr(game->mapcopy[i], 'C')
			|| ft_strchr(game->mapcopy[i], 'E'))
		{
			ft_printf("[ERROR]: Map is invalid! Props remain after fill!\n");
			exit (EXIT_FAILURE);
		}
		else
			ft_printf("Row is valid, moving onto the next\n");
		i++;
	}
}
