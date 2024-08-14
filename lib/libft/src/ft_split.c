/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:38:34 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 13:30:48 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *str, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_memcheck(char **arr, size_t i)
{
	size_t	j;

	j = 0;
	if (arr[i] == 0)
	{
		while (i >= j)
		{
			free (arr[j]);
			j++;
		}
		free (arr);
		return (0);
	}
	return (1);
}

static	char	*ft_passdiv(char const *str, char c)
{
	while (*str == c && *str)
		str++;
	return ((char *)str);
}

static	size_t	ft_wordlen(char const *str, char c)
{
	size_t	wordlen;

	wordlen = ft_strchr(str, c) - str;
	if (ft_strchr(str, c) == 0)
		wordlen = ft_strlen(str);
	return (wordlen);
}

char	**ft_split(char const *str, char c)
{
	char	**ret;
	size_t	word_len;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	ret = (char **)malloc (sizeof(char *) * (ft_wordcount(str, c) + 1));
	if ((str == 0) || (ret == 0))
		return (0);
	while (*str)
	{
		str = ft_passdiv(str, c);
		if (*str)
		{
			word_len = ft_wordlen(str, c);
			ret[i++] = ft_substr(str, 0, word_len);
			if (ft_memcheck(ret, i - 1) == 0)
				return (0);
			str += word_len;
		}
	}
	ret[i] = 0;
	return (ret);
}
/*
#include <stdio.h>

int	main(void)
{
	char const	str[] = "I will split   this  string";
	char		set = ' ';
	int			i = 0;
	char		**ret = ft_split(str, set);

	while (i < 5)
		printf("%s\n", ret[i++]);
	return (0);
}*/
