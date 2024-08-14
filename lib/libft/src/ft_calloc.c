/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:22:54 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 15:46:58 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	limit;

	limit = SIZE_MAX;
	if (count == 0)
		return (NULL);
	if (count > 0 && size > limit / count)
		return (NULL);
	p = malloc (count * size);
	if (p == 0)
		return (p);
	ft_bzero (p, count * size);
	return (p);
}
