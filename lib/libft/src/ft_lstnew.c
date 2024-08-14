/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:24:30 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 13:32:59 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*result;
	char	str[] = "obiwan";

	result = ft_lstnew(str);
	if (result != 0)
	{
		printf("%s\n%d", (char *)result->content, (int)sizeof(t_list));
		free (result);
	}
	return (0);
}*/
