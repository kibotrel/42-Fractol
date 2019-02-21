/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 21:18:45 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/15 18:53:42 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chain	*ft_list_at(t_chain *begin_list, unsigned int nbr)
{
	if (begin_list == NULL)
		return (0);
	while (nbr-- > 0)
	{
		if (begin_list == NULL)
			return (NULL);
		begin_list = begin_list->next;
	}
	return (begin_list);
}
