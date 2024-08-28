/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:24:53 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/08 11:24:54 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "stdlib.h"
# include "stdarg.h"
# include "fcntl.h"

typedef struct s_game
{
  mlx_t *mlx;
  char  **map;
  char  **mapcopy;
  int   row;
  int   column;
  int   move_x;
  int   move_y;
  int   player_count;
  int   collect_count;
  int   move_counter;
  int   exit_count;
  int   exit_game;
  int   locate_player_x;
  int   locate_player_y;
} t_game;

typedef struct s_textures
{
  mlx_texture_t *temp;
  mlx_texture_t *floor;
  mlx_image_t *wall;
  mlx_image_t *collectible;
  mlx_image_t *player;
  mlx_image_t *exit;
} t_textures;

void  read_map(char *argv, t_game *game);
void  fill_map(t_game *game, int move_x, int move_y);
void  find_player(t_game *game, int *player_row, int *player_col);
void  check_name(char *mapname);
void  count_props(t_game *game);
void  check_props(t_game *game);
void  check_borders(t_game *game);
void  check_shape(t_game *game);
void  check_win(t_game *game);
#endif
