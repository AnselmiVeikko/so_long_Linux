/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:38:43 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/02 17:57:17 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	char			*str1;

	str1 = (char *) str;
	i = 0;
	while (i < n)
	{
		str1[i] = c;
		i++;
	}
	return (str1);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char			str[] = "123456789";
	unsigned int	n = 2;
	printf("%s\n", ft_memset(str, 'q', n));
	//printf("%s", memset(str, 'q', n));
	return (0);
			
}*/
