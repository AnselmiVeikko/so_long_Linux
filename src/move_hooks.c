/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:46:29 by ahentton          #+#    #+#             */
/*   Updated: 2024/09/04 10:06:53 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	key_comms(mlx_key_data_t paramkey, t_game *game)
{
	if ((paramkey.key == MLX_KEY_W) && paramkey.action == MLX_PRESS)
		move_player_up(game);
	if ((paramkey.key == MLX_KEY_S) && paramkey.action == MLX_PRESS)
		move_player_down(game);
	if ((paramkey.key == MLX_KEY_A) && paramkey.action == MLX_PRESS)
		move_player_left(game);
	if ((paramkey.key == MLX_KEY_D) && paramkey.action == MLX_PRESS)
		move_player_right(game);
	if ((paramkey.key == MLX_KEY_ESCAPE) && paramkey.action == MLX_PRESS)
		close_game(game);
}

void	move_player_up(t_game *game)
{
	if ((game->map[game->player_y - 1][game->player_x] != '1')
			&& (game->map[game->player_y - 1][game->player_x] != 'E'
				|| game->collect_count == 0))
	{
		if (game->map[game->player_y - 1][game->player_x] == 'C')
			game->collect_count--;
		if (game->map[game->player_y -1][game->player_x] == 'E'
				&& game->collect_count == 0)
			close_game(game);
		game->map[game->player_y - 1][game->player_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->move_counter++;
		ft_printf("[MOVES]:%d\n", game->move_counter);
		render_map(game);
	}
}

void	move_player_down(t_game *game)
{
	if ((game->map[game->player_y + 1][game->player_x] != '1')
			&& (game->map[game->player_y + 1][game->player_x] != 'E'
				|| game->collect_count == 0))
	{
		if (game->map[game->player_y + 1][game->player_x] == 'C')
			game->collect_count--;
		if (game->map[game->player_y + 1][game->player_x] == 'E'
				&& game->collect_count == 0)
			close_game(game);
		game->map[game->player_y + 1][game->player_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->move_counter++;
		ft_printf("[MOVES]:%d\n", game->move_counter);
		render_map(game);
	}
}

void	move_player_left(t_game *game)
{
	if ((game->map[game->player_y][game->player_x - 1] != '1')
			&& (game->map[game->player_y][game->player_x - 1] != 'E'
				|| game->collect_count == 0))
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
			game->collect_count--;
		if (game->map[game->player_y][game->player_x - 1] == 'E'
				&& game->collect_count == 0)
			close_game(game);
		game->map[game->player_y][game->player_x - 1] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->move_counter++;
		ft_printf("[MOVES]:%d\n", game->move_counter);
		render_map(game);
	}
}

void	move_player_right(t_game *game)
{
	if ((game->map[game->player_y][game->player_x + 1] != '1')
			&& (game->map[game->player_y][game->player_x + 1] != 'E'
				|| game->collect_count == 0))
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
			game->collect_count--;
		if (game->map[game->player_y][game->player_x + 1] == 'E'
				&& game->collect_count == 0)
			close_game(game);
		game->map[game->player_y][game->player_x + 1] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->move_counter++;
		ft_printf("[MOVES]:%d\n", game->move_counter);
		render_map(game);
	}
}
