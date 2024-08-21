/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:07:12 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/21 16:07:14 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void  validatename(char *mapname)
{
  int name_len;

  name_len = ft_strlen(mapname);
  if (!ft_strnstr(mapname[name_len - 4], ".ber", 5))
    ft_printf("[ERROR]: Map name is invalid!")
}

void  countprops(t_game *game)
{
  int i;
  int j;

  i = 0;
  while (t_game->map[i])
  {
    j = 0;
    while (t_game->map[i][j])
    {
      if (t_game->map[i][j] == 'P')
        game->player_count++;
      if (t_game->map[i][j] == 'C')
        game->collect_count++;
      if (t_game->map[i][j] == 'E')
        game->exit_count++;
      j++;
    }
    i++;
  }
}

int checkcount(t_game *game)
{
  if (game->player_count != 1)
  {
    ft_printf("[ERROR]: Invalid amount of player characters!");
    return (-1);
  }
  if (game->exit_count != 1)
  {
    ft_printf("[ERROR]: Invalid amount of exits!");
    return (-1);
  }
  if (game->collect_count < 1)
  {
    ft_printf("[ERROR]: Invalid amount of collectibles!");
    return (-1);
  }
  return (1);
}

void  checkborders(t_game *game)
{
  
}
