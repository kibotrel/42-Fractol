/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:11:52 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/16 14:52:56 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_list_remove_if(t_chain **begin_list, void *data_ref, int (*cmp)())
{
	t_chain *position;
	t_chain	*previous;
	t_chain *tmp;

	if (!begin_list)
		return ;
	position = *begin_list;
	previous = NULL;
	while (position)
	{
		if ((*cmp)(position->data, data_ref) == 0)
		{
			if (position == *begin_list)
				*begin_list = position->next;
			(previous) ? previous->next = position->next : 0;
			tmp = position;
			position = position->next;
			free(tmp);
		}
		else
		{
			previous = position;
			position = position->next;
		}
	}
}
