/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:24:51 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 13:33:19 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	**res;
	t_list	*new;

	res = (t_list **)malloc(sizeof(t_list));
	new = ft_lstnew("hello there");
	ft_lstadd_front(res, new);
	printf("%s\n%d", res[0]->content, (int)res[0]->next);
	free (new);
	free (res);
	return (0);
}*/
