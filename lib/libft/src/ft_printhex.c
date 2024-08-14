/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:03:11 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/20 12:48:37 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
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

char	*ft_hextoa(unsigned int n, char *str)
{
	char	*ret;
	int		i;
	int		len;

	if (n == 0)
		return (NULL);
	len = ft_hexlen(n);
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

int	ft_printhex(const char form, unsigned int n)
{
	char	*hex;
	int		hexlen;

	if (n == 0)
		return (ft_printstr("0"));
	hexlen = 0;
	if (form == 'X')
		hex = ft_hextoa(n, "0123456789ABCDEF");
	else
		hex = ft_hextoa(n, "0123456789abcdef");
	if (hex == NULL)
		return (-1);
	hexlen = ft_printstr(hex);
	free (hex);
	return (hexlen);
}
