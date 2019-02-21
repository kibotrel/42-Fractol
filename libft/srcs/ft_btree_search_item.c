/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:46:29 by kibotrel          #+#    #+#             */
/*   Updated: 2019/01/16 01:37:13 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*value;

	value = NULL;
	if (!root)
		return (NULL);
	if (root->left)
		value = ft_btree_search_item(root->left, data_ref, cmpf);
	if ((cmpf(root->item, data_ref)) == 0)
		return (root->item);
	if (root->right != NULL && value != NULL)
		value = ft_btree_search_item(root->right, data_ref, cmpf);
	return (value);
}
