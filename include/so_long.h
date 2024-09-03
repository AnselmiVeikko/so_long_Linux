/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:24:53 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/28 12:35:14 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "stdlib.h"
# include "stdarg.h"
# include "fcntl.h"

# define SI 32
typedef struct s_game
{
	mlx_t	*mlx;
	char	**map;
	char	**mapcopy;
	int		row;
	int		index;
	int		player_count;
	int		collect_count;
	int		move_counter;
	int		exit_count;
	int		exit_game;
	int		player_x;
	int		player_y;

	mlx_texture_t *temp;
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*collectible;
	mlx_image_t		*player;
	mlx_image_t		*exit;
}	t_game;

void	check_rows(t_game *game);
void	read_map(char *argv, t_game *game);
void	fill_map(t_game *game, int x, int y);
void	find_player(t_game *game, int *player_row, int *player_index);
void	count_props(t_game *game);

int		count_row(t_game *game);
int		count_index(t_game *game);
int		count_collectibles(t_game *game);

void	check_mapname(char *mapname);
void	check_args(int argc);
void	check_props(t_game *game);
void	check_borders(t_game *game);
void	check_shape(t_game *game);
void	check_win(t_game *game);
void	validate_map(t_game *game);

void	init_game(t_game *game);
void	init_textures(t_game *game);

void	render_walls(t_game *game, int row, int index);
void	render_exit(t_game *game, int row, int index);
void	render_player(t_game *game, int row, int index);
void	render_collectibles(t_game *game, int row, int index);
void	render_map(t_game *game);

void	key_comms(mlx_key_data_t paramkey, t_game *game);
void	move_player_up(t_game *game);
void	move_player_down(t_game *game);
void	move_player_left(t_game *game);
void	move_player_right(t_game *game);

void	error_exit(char *str);
void	close_game(t_game *game);

#endif
