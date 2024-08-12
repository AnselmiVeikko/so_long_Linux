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
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data
{
  void  *mlx_ptr;
  void  *win_ptr;
} t_data;

int on_destroy(t_data *data)
{
  mlx_destroy_window(data->mlx_ptr, data->win_ptr);
  free(data->mlx_ptr);
  exit (0);
  return (0);
}

int on_keypress(int keysym, t_data *data)
{
  (void)data;
  printf("Pressed key: %d\\n", keysym);
  return (0);
}

int main(void)
{
  t_data data;

  data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "Hi :)");
  if (!data.win_ptr)
    return (free(data.mlx_ptr), 1);

  mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
  mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
  mlx_loop(data.mlx_ptr);
  return (0);
}
