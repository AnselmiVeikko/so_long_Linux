/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:19:41 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/23 10:19:46 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int  checkname(char *mapname)
{
  int name_len;

  name_len = ft_strlen(mapname);
  if (!ft_strnstr(mapname[name_len - 4], ".ber", 5))
  {
    ft_printf("[ERROR]: Map name is invalid!");
    return (-1);
  }
  return (1);
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

int checkprops(t_game *game)
{
  if (game->player_count != 1)
  {
    ft_printf("[MAP ERROR]: Invalid amount of player characters!\n");
    return (-1);
  }
  if (game->exit_count != 1)
  {
    ft_printf("[MAP ERROR]: Invalid amount of exits!\n");
    return (-1);
  }
  if (game->collect_count < 1)
  {
    ft_printf("[MAP ERROR]: Invalid amount of collectibles!\n");
    return (-1);
  }
  return (1);
}

int  checkborders(t_game *game)
{
  int i;
  int j;

  while (game->row)
  {
    while (game->colum)
      game->colum++;
    game->row++;
  }
  i = 0;
  while (game->map[i])
  {
    while (game->map[i][j])
    {
      if (i == 0 || i == game->row - 1
        || x == 0 || x == game->colum -1)
        if (game->map[i][j] != '1')
        {
          ft_printf("[MAP ERROR]: Invalid map, borders are not closed properly!\n");
          return (-1)
        }
      j++;
    }
    i++;
  }
  return (1);
}

int  checkshape(t_game *game)
{
  int row_len;
  int i;

  row_len = ft_strlen(game->map[0])
  while (game->map[i])
  {
    if (row_len != ft_strlen(game->map[i]))
    {
      ft_printf("[MAP ERROR]: Map is not rectangular... seriously?\n");
      return (-1);
    }
    i++;
  }
  return (1);
}
