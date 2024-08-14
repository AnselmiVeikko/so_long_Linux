/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:25:42 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 13:33:37 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_setcon(void *content)
{
	char	*str;
	char	**ptr;

	ptr = (char **)content;
	str = "success";
	*ptr = str;
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*test1;
	t_list	*test2;
	t_list	*test3;

	test1 = ft_lstnew("failed");
	test2 = ft_lstnew("failed");
	test3 = ft_lstnew("failed");

	test1->next = test2;
	test2->next = test3;

	ft_lstiter(test1, ft_setcon);
	printf("%s\n%s\n%s", test1->content, test2->content, test3->content);
	return (0);
}*/
