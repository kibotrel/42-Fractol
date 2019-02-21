/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:46:07 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/15 20:03:22 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_chain **begin_list, void *data)
{
	t_chain	*head;

	head = *begin_list;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
