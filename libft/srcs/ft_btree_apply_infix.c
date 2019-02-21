/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 17:37:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/01/15 23:28:38 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *src, void (*applyf)(void *))
{
	if (src)
	{
		ft_btree_apply_infix(src->left, applyf);
		(*applyf)(src->item);
		ft_btree_apply_infix(src->right, applyf);
	}
}
