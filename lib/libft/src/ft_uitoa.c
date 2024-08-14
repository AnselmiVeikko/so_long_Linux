/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:17:07 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/20 12:48:48 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	unsigned int	ft_nblen(unsigned int n)
{
	unsigned int	nb_len;

	nb_len = 0;
	while (n > 0)
	{
		nb_len++;
		n = n / 10;
	}
	return (nb_len);
}

static void	ft_convert(unsigned int n, char *str)
{
	unsigned int	nb_len;
	unsigned int	i;

	nb_len = ft_nblen(n);
	i = nb_len - 1;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[nb_len] = '\0';
}

char	*ft_uitoa(unsigned int n)
{
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	ret = (char *)malloc(sizeof(char) * (ft_nblen(n) + 1));
	if (!ret)
		return (NULL);
	ft_convert(n, ret);
	return (ret);
}
