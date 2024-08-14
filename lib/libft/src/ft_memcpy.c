/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:21:04 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/02 17:59:09 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest1;
	const unsigned char	*src1;
	size_t				i;

	dest1 = (unsigned char *) dest;
	src1 = (const unsigned char *) src;
	i = 0;
	if (!src1 && !dest1)
		return (0);
	while (n > 0)
	{
		dest1[i] = src1[i];
		i++;
		n--;
	}
	return (dest1);
}
