/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:47:55 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/02 18:09:46 by ahentton         ###   ########.fr       */
/*   Updated: 2024/04/18 20:40:38 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	ret;
	long	check;

	i = 0;
	ret = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = ret;
		ret = ret * 10 + str[i++] - '0';
		if (check > ret && sign == 1)
			return (-1);
		if (check > ret && sign == -1)
			return (0);
	}
	return ((int)(ret * sign));
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "	 -21ab47";

	printf("%d\n%d", ft_atoi(str), atoi(str));
	return (0);
}*/
