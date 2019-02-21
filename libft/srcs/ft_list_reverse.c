/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 10:18:31 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/15 19:12:24 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_chain **begin_list)
{
	t_chain	*list1;
	t_chain	*list2;
	t_chain	*list3;

	list1 = *begin_list;
	list2 = 0;
	list3 = 0;
	if (*begin_list)
	{
		while (list1)
		{
			list3 = list2;
			list2 = list1;
			list1 = list1->next;
			list2->next = list3;
		}
		*begin_list = list2;
	}
}
