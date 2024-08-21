/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:19:49 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/21 11:18:03 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map(char *argv, t_game *game)
{
	int		map;
	char	*line;
	char	*map_buffer;

	map = open(argv, O_RDONLY);
	map_buffer = ft_strdup("");
	if (map == -1)
		ft_printf("[ERROR]: The file is invalid or empty");
	line = get_next_line(map);
	if (!line)
		ft_printf("[ERROR]: File is Empty!");
	while (line)
	{
		map_buffer = ft_strjoin(map_buffer, line);
		free (line);
		line = get_next_line(map);
	}
	free (line);
	close(map);
	game->map = ft_split(map_buffer, '\n');
	game->mapcopy = ft_split(map_buffer, '\n');
	free (map_buffer);
}

void	fill_map(t_game *game, int move_x, int move_y)
{
	if (move_x < 0 || move_y < 0 || move_x >= game->colum
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

void	find_player(t_game *game, int *player_row, int *player_col)
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
				*player_col = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_game *game)
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
		if (ft_strchr(game->mapcopy[i], 'C') || ft_strchr(game->mapcopy[i], 'E'))
			ft_printf("[ERROR]: Map is invalid!\n");
		else
			ft_printf("Row is valid, moving onto the next\n");
		i++;
	}
}
