/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:12:36 by ahentton          #+#    #+#             */
/*   Updated: 2024/08/23 12:12:38 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void  validatemap(t_game *game, char *argv)
{
  check_name(argv);
  check_props(game);
  check_borders(game);
  check_shape(game);
  check_map(game);
}
