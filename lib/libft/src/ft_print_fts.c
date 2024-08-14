/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:17:20 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/20 12:48:25 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../include/libft.h"
int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (write (1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_printchar(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printnbr(int n)
{
	long	nbrlen;
	char	*nbr;

	nbrlen = (long) n;
	if (nbrlen < -2147483648 || nbrlen > 2147483647)
		return (-1);
	nbrlen = 0;
	nbr = ft_itoa(n);
	if (nbr == 0)
		return (-1);
	nbrlen = ft_printstr(nbr);
	free (nbr);
	return ((int)nbrlen);
}

int	ft_print_ui(unsigned int n)
{
	char	*nbr;
	int		nbrlen;

	nbr = ft_uitoa(n);
	if (nbr == 0)
		return (-1);
	nbrlen = ft_printstr(nbr);
	free (nbr);
	return (nbrlen);
}

int	ft_printper(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
