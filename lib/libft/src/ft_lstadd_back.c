/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:24:42 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 13:33:14 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	**list;
	t_list	*test1;
	t_list	*test2;
	t_list	*new;

	test1 = ft_lstnew("obiwan");
	test2 = ft_lstnew("is");
	new = ft_lstnew("kenobi");

	list = (t_list **)malloc(sizeof(t_list));
	if (list == 0)
		printf("malloc failed");

	list[0] = test1;
	test1->next = test2;
	ft_lstadd_back(list, new);
	printf("%s\n%s", list[0]->content, list[0]->next->next->content);

	free(test1);
	free(test2);
	free(new);
	free(list);
	return (0);
}*/
