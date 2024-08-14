/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:54:08 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 12:27:43 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	if ((!dst) || (!src && !dstsize))
		return (0);
	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < dstsize)
		dst[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
/*
#include <strings.h>
#include <stdio.h>

int	main(void)
{
	char	str[15] = "Obiwan";
	char	str2[] = "Kenobi000";
	int		x;

	x = ft_strlcat(str, str2, 0);
	ft_strlcat(str, str2, 0);
	printf("%s\n%d", str, x);
	return (0);
}*/
