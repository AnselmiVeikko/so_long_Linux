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
	if (move_x < 0 || move_y < 0 || move_x >= game->column
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
	game->macopy[move_x][move_y] = 'X';
	flood_fill(game, move_x - 1, move_y);
	flood_fill(game, move_x + 1, move_y);
	flood_fill(game, move_x, move_y - 1);
	flood_fill(game, move_x, move_y + 1);
}
