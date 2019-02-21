/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:01:06 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/15 17:12:36 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *position;
	t_list *previous;
	t_list *tmp;

	if (alst)
	{
		position = *alst;
		previous = NULL;
		while (position)
		{
			if (position && del)
			{
				if (position == *alst)
					*alst = position->next;
				(previous) ? previous->next = position->next : 0;
				tmp = position;
				position = position->next;
				del(tmp->content, tmp->content_size);
				free(tmp);
			}
		}
	}
}
