/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:19:49 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/23 12:43:58 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map(char *argv, t_game *game)
{
	int		map;
	char	*row;
	char	*map_buffer;

	map = open(argv, O_RDONLY);
	map_buffer = ft_strdup("");
	if (map == -1)
		ft_printf("[ERROR]: The file is invalid or empty");
	row = get_next_line(map);
	if (!row)
		ft_printf("[ERROR]: File is Empty!");
	while (row)
	{
		map_buffer = ft_strjoin(map_buffer, row);
		free (row);
		row = get_next_line(map);
	}
	free (row);
	close(map);
	game->map = ft_split(map_buffer, '\n');
	game->mapcopy = ft_split(map_buffer, '\n');
	free (map_buffer);
}

void	fill_map(t_game *game, int move_x, int move_y)
{
	if (move_x < 0 || move_y < 0 || move_x >= game->index
		|| move_y >= game->row || game->mapcopy[move_x][move_y] == '1'
			|| game->mapcopy[move_x][move_y] == 'X')
		return ;
	if (((game->mapcopy[move_x + 1][move_y] == 'E')
		|| (game->mapcopy[move_x - 1][move_y] == 'E'))
			&& ((game->mapcopy[move_x][move_y + 1] == '1')
				|| (game->mapcopy[move_x][move_y - 1] == '1')))
		return ;
	if (((game->mapcopy[move_x][move_y + 1] == 'E'
			|| game->mapcopy[move_x][move_y - 1] == 'E'))
			&& ((game->mapcopy[move_x + 1][move_y] == '1')
				|| (game->mapcopy[move_x - 1][move_y] == '1')))
		return ;
	if (game->mapcopy[move_x][move_y] == 'E'
			|| game->mapcopy[move_x][move_y] == 'C')
		game->mapcopy[move_x][move_y] = '0';
	game->mapcopy[move_x][move_y] = 'X';
	fill_map(game, move_x - 1, move_y);
	fill_map(game, move_x + 1, move_y);
	fill_map(game, move_x, move_y - 1);
	fill_map(game, move_x, move_y + 1);
}

void	find_player(t_game *game, int *player_row, int *player_index)
{
	int	i;
	int	j;

	i = 0;
	while (game->mapcopy[i])
	{
		j = 0;
		while (game->mapcopy[i][j])
		{
			if (game->mapcopy[i][j] == 'P')
			{
				*player_row = i;
				*player_index = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	countprops(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->player_count++;
			if (game->map[i][j] == 'C')
				game->collect_count++;
			if (game->map[i][j] == 'E')
				game->exit_count++;
			j++;
		}
		i++;
	}
}
