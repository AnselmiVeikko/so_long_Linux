/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:06:21 by ahentton          #+#    #+#             */
/*   Updated: 2024/09/03 10:06:22 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void  close_window(mlx_key_data_t paramkey, t_game *game)
{
  if ((paramkey.key == MLX_KEY_ESCAPE) && paramkey.action == MLX_PRESS)
    close_game(game->mlx, texture);
}
