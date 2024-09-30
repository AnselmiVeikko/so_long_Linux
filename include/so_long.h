/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:24:53 by ahentton          #+#    #+#             */
/*   Updated: 2024/09/04 10:46:55 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "stdlib.h"
# include "stdarg.h"
# include "fcntl.h"

# define TILE 32

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				y_size;
	int				x_size;
	int				player_count;
	int				collect_count;
	int				move_counter;
	int				exit_count;
	int				player_x;
	int				player_y;
	mlx_texture_t	*temp;
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*collectible;
	mlx_image_t		*player;
	mlx_image_t		*exit;
}			t_game;

char	*parse_map(char *argv);
char	**split_map(char *argv);
void	fill_map(char **map, int x, int y);

void	check_map(t_game *game, char *argv);

int		find_player_y(char **map);
int		find_player_x(char **map);
int		count_y(char **map);
int		count_x(char **map);
void	count_props(t_game *game);
t_game	*init_game(char *argv);

void	init_textures(t_game *game);
void	render_map(t_game *game);

void	key_comms(mlx_key_data_t paramkey, t_game *game);

int		ft_notchar(char *str, char c);
void	error_exit(char *str);
void	free_map(char **map);
void	close_game(t_game *game);

#endif
