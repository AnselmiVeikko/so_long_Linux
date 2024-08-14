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

# define TILES 64
# define PATH_W "./assets/wall.xpm"
# define PATH_F "./assets/floor.xpm"
# define PATH_EX "./assets/exit.xpm"
# define PATH_P "./assets/player.xpm"
# define PATH_C "./assets/collectible.xpm"

typedef struct s_data
{
  void  *mlx_ptr;
  void  *win_ptr;
  void  *textures[5];
  t_map *map;
} t_data;

#endif
