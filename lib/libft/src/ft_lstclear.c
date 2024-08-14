/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahentton <ahentton@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:25:33 by ahentton          #+#    #+#             */
/*   Updated: 2024/05/07 13:33:26 by ahentton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static	void	ft_freecon(void *content)
{
	free (content);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list	*new;
	t_list	**list;

	list = (t_list **)malloc(sizeof(t_list) * 2);

	node1 = ft_lstnew("delete");
	new = ft_lstnew("please");

	list[0] = node1;
	ft_lstadd_back(list, new);

	printf("%s\n%s\n", list[0]->content, list[0]->next->content);
	ft_lstclear(list, ft_freecon);
	printf("%s\n%s", list[0]->content, list[0]->next->content);
	return (0);

}*/
