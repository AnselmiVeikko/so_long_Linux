/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:43:11 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/02 17:58:14 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*str1;
	int		i;

	str1 = (char *) str;
	i = 0;
	while (n > 0)
	{
		str1[i] = 0;
		i++;
		n--;
	}
}
/*
#include <strings.h>
#include <stdio.h>

int	main(void)
{
	char	str[] = "kenobi";
	ft_bzero(str, 3);
	printf("%s", str);
	return (0);
}*/
