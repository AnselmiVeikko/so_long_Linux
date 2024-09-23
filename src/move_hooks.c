/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:35:46 by ahentton          #+#    #+#             */
/*   Updated: 2024/09/23 15:35:47 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game, int move_y, int move_x)
{
	if ((game->map[move_y][move_x] != '1')
			&& (game->map[move_y][move_x] != 'E'
				|| game->collect_count == 0))
	{
		if (game->map[move_y][move_x] == 'C')
			game->collect_count--;
		if (game->map[move_y][move_x] == 'E'
				&& game->collect_count == 0)
			close_game(game);
		game->map[move_y][move_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->move_counter++;
		ft_printf("[MOVES]:%d\n", game->move_counter);
		render_map(game);
	}
}

void	key_comms(mlx_key_data_t paramkey, t_game *game)
{
	if ((paramkey.key == MLX_KEY_W) && paramkey.action == MLX_PRESS)
		move_player(game, game->player_y - 1, game->player_x);
	if ((paramkey.key == MLX_KEY_S) && paramkey.action == MLX_PRESS)
		move_player(game, game->player_y + 1, game->player_x);
	if ((paramkey.key == MLX_KEY_A) && paramkey.action == MLX_PRESS)
		move_player(game, game->player_y, game->player_x - 1);
	if ((paramkey.key == MLX_KEY_D) && paramkey.action == MLX_PRESS)
		move_player(game, game->player_y, game->player_x + 1);
	if ((paramkey.key == MLX_KEY_ESCAPE) && paramkey.action == MLX_PRESS)
		close_game(game);
}	
