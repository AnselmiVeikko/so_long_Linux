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

char	*parse_map(char	*argv)
{
	int		read_map;
	char	*line;
	char	*map_buffer;

	map_buffer = ft_calloc(1, 1);
	if (!map_buffer)
		return (NULL);
	read_map = open(argv, O_RDONLY);
	if (read_map == -1)
		return (free_null(&map_buffer, 0));
	line = get_next_line(read_map);
	if (!line)
		return (free_null(&map_buffer, 0));
	while (line)
	{
		map_buffer = gnl_strjoin(map_buffer, line);
		free (line);
		line = get_next_line(read_map);
	}
	free (line);
	return (map_buffer);
}

char	**split_map(char *argv)
{
	char	*map;
	char	**split_map;

	map = parse_map(argv);
	if (!map)
		return (NULL);
	split_map = ft_split(map, '\n');
	free(map);
	return (split_map);
}
