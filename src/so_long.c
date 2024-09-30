/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:00:11 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/28 11:23:32 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	check_args(int argc)
{
	if (argc > 2)
		error_exit("Error\nToo many arguments! Only one argument expected.");
	if (argc < 2)
		error_exit("Error\nToo few arguments! One argument expected.");
}

static	void	check_mapname(char *str)
{
	size_t	name_len;

	name_len = ft_strlen(str);
	if (!ft_strnstr(&str[name_len - 4], ".ber", 5))
		error_exit("Error\nMap name is invalid!\n");
}

static	void	check_chars(char *str)
{
	int		i;
	int		error;
	char	*map;

	map = parse_map(str);
	if (!map)
		error_exit("Error\nMap file is invalid or empty\n");
	i = 0;
	while (map[i])
	{
		error = 1;
		if (map[i] == 'C' || map[i] == 'P')
			error = 0;
		if (map[i] == 'E' || map[i] == '1')
			error = 0;
		if (map[i] == '0' || map[i] == '\n')
			error = 0;
		if (error == 1)
		{
			free(map);
			error_exit("Error\nInvalid characters in the map file\n");
		}
		i++;
	}
	free(map);
}

int	main(int argc, char *argv[])
{
	t_game		*game;

	check_args(argc);
	check_mapname(argv[1]);
	check_chars(argv[1]);
	game = init_game(argv[1]);
	check_map(game, argv[1]);
	game->mlx = mlx_init(game->x_size * TILE, game->y_size * TILE, "SL", false);
	init_textures(game);
	render_map(game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)key_comms, game);
	mlx_loop(game->mlx);
	close_game(game);
	return (0);
}
