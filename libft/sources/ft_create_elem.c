/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:44:53 by kibotrel          #+#    #+#             */
/*   Updated: 2019/01/15 23:38:25 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_chain	*ft_create_elem(void *data)
{
	t_chain *new;

	if (!(new = (t_chain*)malloc(sizeof(*new))))
		return (0);
	if (data)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}
