/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:59:08 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/15 17:12:25 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_push_back(t_list **begin_list, t_list *data)
{
	t_list	*head;

	head = *begin_list;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = data;
	}
	else
		*begin_list = data;
}

t_list		*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*map;
	t_list	*new;

	map = NULL;
	while (lst)
	{
		if (!(new = f(lst)))
			return (0);
		ft_push_back(&map, new);
		lst = lst->next;
	}
	return (map);
}
