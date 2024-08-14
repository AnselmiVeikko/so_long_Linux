/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:48:33 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 11:53:56 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static	void	ft_lowercase(unsigned int i, char *str)
{
	i = 32;
	*str = *str + i;
}
*/
void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = NULL;

	ft_striteri(str, ft_lowercase);
	printf("%s", str);
	return (0);
}*/
