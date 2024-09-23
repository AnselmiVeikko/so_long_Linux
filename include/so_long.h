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
	int				exit_game;
	int				player_x;
	int				player_y;
	mlx_texture_t	*temp;
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*collectible;
	mlx_image_t		*player;
	mlx_image_t		*exit;
}			t_game;

char	**read_map(char *argv);
void	check_rows(t_game *game);
void	fill_map(char **map, int x, int y);
void	count_props(t_game *game);

void	check_mapname(char *mapname);
void	check_args(int argc);
void	check_props(t_game *game);
void	check_borders(t_game *game);
void	check_shape(t_game *game);
void	check_win(t_game *game, char *argv);
void	validate_map(t_game *game, char *argv);

void	init_game(t_game *game, char *argv);
int	find_player_y(t_game *game);
int	find_player_x(t_game *game);
int	init_y(t_game *game);
int	init_x(t_game *game);
void	init_textures(t_game *game);

void	render_map(t_game *game);

void	move_player(t_game *game, int move_y, int move_x);
void	key_comms(mlx_key_data_t paramkey, t_game *game);

void	error_exit(char *str);
void	free_map(char **map);
void	close_game(t_game *game);

#endif
