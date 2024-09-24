/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:19:49 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/23 12:43:58 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_mapname(char *mapname)
{
	size_t	name_len;

	name_len = ft_strlen(mapname);
	if (!ft_strnstr(&mapname[name_len - 4], ".ber", 5))
		error_exit("Error\nMap name is invalid!\n");
}

char	**split_map(char *argv)
{
	int		read_map;
	char	*row;
	char	*map_buffer;
	char	**map;

	read_map = open(argv, O_RDONLY);
	map_buffer = ft_strdup("");
	if (read_map == -1)
		error_exit("Error\n The file is invalid or empty");
	row = get_next_line(read_map);
	if (!row)
		error_exit("Error\n File is Empty!");
	while (row)
	{
		map_buffer = ft_strjoin(map_buffer, row);
		free (row);
		row = get_next_line(read_map);
	}
	free (row);
	close(read_map);
	map = ft_split(map_buffer, '\n');
	free(map_buffer);
	return (map);
}

void	fill_map(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	fill_map(map, y - 1, x);
	fill_map(map, y + 1, x);
	fill_map(map, y, x - 1);
	fill_map(map, y, x + 1);
}
