/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:25:21 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 13:34:21 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*test1;
	t_list	*test2;
	t_list	*test3;
	t_list	*result;

	test1 = ft_lstnew("nice");
	test2 = ft_lstnew("one");
	test3 = ft_lstnew("brudda");
	
	test1->next = test2;
	test2->next = test3;

	result = ft_lstlast(test1);
	printf("%s", result->content);
	free (test1);
	free (test2);
	free (test3);
	return (0);
}*/
