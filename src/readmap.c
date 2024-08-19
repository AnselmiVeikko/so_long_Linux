/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:19:49 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/16 16:19:50 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void read_map(char *argv, t_game *game)
{
  int   fd_map;
  char  *temp;
  char  *big_str;
  char  *str;

  fd_map = open(argv, O_RDONLY);
  big_str = ft_strdup("");
  if (fd_map == -1)
    ft_printf("File error or empty");
  str = get_next_line(fd_map);
  if (!str)
    ft_printf("Empty file");
 while (str)
  {
    temp = ft_strjoin(big_str, str);
    free (big_str);
    big_str = temp;
    free (str);
    str = get_next_line(fd_map);
  }
  free (str);
  free (temp);
  close(fd_map);
  game->map = ft_split(big_str, '\n');
  game->mapcopy = ft_split(big_str, '\n');
}

int main(int argc, char *argv[])
{
  t_game game;

  if (argc == 2)
  {
    read_map(argv[1], &game);
    ft_printf("%s", game.map);
  }
  return (0);
}
