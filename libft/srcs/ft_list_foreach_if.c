/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:45:15 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/15 20:00:49 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach_if(t_chain *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_chain	*position;

	position = begin_list;
	while (position)
	{
		if ((*cmp)(position->data, data_ref) == 0)
			(*f)(position->data);
		position = position->next;
	}
}
