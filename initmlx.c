/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:30:11 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/08 11:42:13 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>

int main(void)
{
  void	*mlx_ptr;
  void  *win_ptr;

  mlx_ptr = mlx_init();
  if (!mlx_ptr)
    return (1);
  win_ptr = mlx_new_window(mlx_ptr, 600, 400, "Maze");
  if (!win_ptr)
  {
    free (mlx_ptr);
    return (1);
  }
  //mlx_destroy_window(mlx_ptr, win_ptr);
  free (mlx_ptr);
  return (0);
}
