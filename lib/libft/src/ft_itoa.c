/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:26:25 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/02 18:39:19 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int n)
{
	int	nb_len;

	nb_len = 0;
	while (n > 0)
	{
		nb_len++;
		n = n / 10;
	}
	return (nb_len);
}

static void	ft_convert(int n, char *str, int i)
{
	int	nb_len;

	nb_len = ft_nblen(n);
	if (i == 0)
		nb_len--;
	while (i < nb_len)
		i++;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[nb_len + 1] = '\0';
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		checkminus;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	checkminus = 0;
	if (n < 0)
	{
		n = n * -1;
		checkminus = 1;
	}
	ret = (char *)malloc(sizeof(char) * (ft_nblen(n) + 1 + checkminus));
	if (!ret)
		return (0);
	if (checkminus == 1)
		ret[0] = '-';
	ft_convert(n, ret, checkminus);
	return (ret);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	result = ft_itoa(-2147483648);
	printf("%s", result);
}*/
