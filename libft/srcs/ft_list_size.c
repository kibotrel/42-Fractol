/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 10:36:08 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/15 19:13:38 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_chain *begin_list)
{
	int count;

	count = 0;
	if (begin_list == 0)
		return (0);
	while (begin_list != 0)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}
