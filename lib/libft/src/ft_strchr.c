/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:03:24 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/06 12:06:56 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ret;

	ret = (char *) str;
	i = 0;
	while (ret[i])
	{
		if (ret[i] == (char) c)
			return (&ret[i]);
		i++;
	}
	if ((char) c == '\0')
		return (&ret[i]);
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str[] = "Obiwanken\0com";
	char	*result;

	result = strchr(str, '\0');
	printf("%s", result);
	return (0);
}*/
