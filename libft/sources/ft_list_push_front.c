/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 10:25:24 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/15 19:05:58 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_chain **begin_list, void *data)
{
	t_chain	*first_elem;

	first_elem = ft_create_elem(data);
	first_elem->next = *begin_list;
	*begin_list = first_elem;
}
