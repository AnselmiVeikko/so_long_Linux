/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:17:53 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/02 18:02:45 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlength(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*ret;

	ret = (char *) str;
	i = ft_strlength(ret) - 1;
	while (i >= 0)
	{
		if (ret[i] == (char) c)
			return (&ret[i]);
		i--;
	}
	if ((char) c == '\0')
	{
		i = ft_strlength(ret);
		return (&ret[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "obiwanke\0nobi";
	char	*result;

	result = ft_strrchr(str, '\0');
	printf("%s", result);
	return (0);
}*/
