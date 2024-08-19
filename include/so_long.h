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
  int   colum;
  int   move_x;
  int   move_y;
  int   player_count;
  int   collect_count;
  int   move_count;
  int   exit_count;
  int   exit_game;
  int   locate_player_x;
  int   locate_player_y;
  mlx_texture_t *temp;
  mlx_image_t *wall;
  mlx_image_t *collect;
  mlx_image_t *player;
  mlx_image_t *exit;
} t_game;
#endif
