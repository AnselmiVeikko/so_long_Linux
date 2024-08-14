/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:24:59 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 13:33:50 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static	void	ft_freecont(void *content)
{
	free (content);
}

static	void	*ft_altercont(void *content)
{
	char	*str;

	if (!content)
		return (0);
	str = (char *) content;
	str = "success";
	return (str);

}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*temp;

	if (!lst || !f || !del)
		return (0);
	new_lst = 0;
	while (lst)
	{
		temp = f(lst->content);
		new_node = ft_lstnew(temp);
		if (!new_node)
		{
			(*del)(temp);
			ft_lstclear(&new_node, del);
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*test1;
	t_list	*test2;
	t_list	*test3;
	t_list	*result;

	test1 = ft_lstnew("failed");
	test2 = ft_lstnew("failed");
	test3 = ft_lstnew("failed");

	test1->next = test2;
	test2->next = test3;

	result = (t_list *)malloc(sizeof(t_list));
	result = ft_lstmap(test1, ft_altercont, ft_freecont);
	printf("%s\n%s\n", result->content, result->next->content);
	printf("%s", result->next->next->content);
	return (0);

}*/
