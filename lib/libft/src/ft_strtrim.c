/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:43:40 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/02 18:18:34 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	if (set == 0)
		return ((char *) s1);
	while (ft_isset(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	while (ft_isset(s1[end], set))
		end--;
	ret = malloc (sizeof (char) * (end - start + 2));
	if (ret == 0)
		return (0);
	while (start <= end)
		ret[i++] = s1[start++];
	ret[i] = '\0';
	return (ret);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*result;
	char	set[] = " \t\n";

	result = ft_strtrim(" \t \t \n  \n\n\n\t", set);
	printf("%s", result);
	return (0);
}*/
