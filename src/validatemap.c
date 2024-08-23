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
			if (ft_strchr("1PCE0", game->map[i][j]))
			{
				ft_printf("[MAP ERROR]: Invalid characters in the map file!");
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_args(int argc)
{
	if (argc > 2)
	{
		ft_printf("[ERROR]: Too many arguments! Only one argument expected.");
		exit (EXIT_FAILURE);
	}
	if (argc < 2)
	{
		ft_printf("[ERROR]: Too few arguments! One argument expected.");
		exit (EXIT_FAILURE);
	}
}

void	validate_map(t_game *game, int argc, char *argv)
{
	check_name(argv);
	check_props(game);
	check_borders(game);
	check_shape(game);
	check_win(game);
	check_map(game);
	check_args(argc);
}
