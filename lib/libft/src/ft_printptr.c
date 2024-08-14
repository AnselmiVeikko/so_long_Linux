/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:40:00 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/20 12:48:40 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen2(unsigned long long n)
{
	int	len;

	len = 0;
	while (n >= 1)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*ft_hextoa2(unsigned long long n, char *str)
{
	char	*ret;
	int		i;
	int		len;

	if (n == 0)
		return (NULL);
	len = ft_hexlen2(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		ret[i] = str[n % 16];
		n = n / 16;
		i--;
	}
	ret[len] = '\0';
	return (ret);
}

int	ft_printptr(void *ptr)
{
	unsigned long long	temp;
	char				*ret;
	int					ptrlen;
	int					retlen;

	temp = (unsigned long long) ptr;
	if (temp == 0)
		return (ft_printstr("0x0"));
	ret = ft_hextoa2(temp, "0123456789abcdef");
	if (ret == NULL)
		return (-1);
	ptrlen = ft_printstr("0x");
	if (ptrlen == -1)
	{
		free(ret);
		return (-1);
	}
	retlen = ft_printstr(ret);
	free (ret);
	ptrlen += retlen;
	return (ptrlen);
}
