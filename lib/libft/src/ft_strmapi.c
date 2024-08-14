/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:01:54 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/02 18:49:11 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static	char	ft_uppercase(unsigned int i, char c)
{
	char	ret;

	i = 32;
	ret = c - i;
	return (ret);
}
*/
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	newstr = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!newstr)
		return (0);
	while (str[i] != '\0')
	{
		newstr[i] = f(i, str[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*result;
	char	str[] = "abcdefg";

	result = ft_strmapi(str, ft_uppercase );
	printf("%s\n%s", str, result);
	return (0);
}*/
