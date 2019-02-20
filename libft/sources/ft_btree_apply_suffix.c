/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:20:13 by kibotrel          #+#    #+#             */
/*   Updated: 2019/01/15 23:29:16 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_suffix(t_btree *src, void (*applyf)(void *))
{
	if (src)
	{
		ft_btree_apply_suffix(src->left, applyf);
		ft_btree_apply_suffix(src->right, applyf);
		(*applyf)(src->item);
	}
}
