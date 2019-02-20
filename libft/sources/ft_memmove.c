/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:27:04 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/25 17:49:23 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned const char	*source;
	unsigned char		*dest;
	size_t				i;

	source = (unsigned const char*)src;
	dest = (unsigned char*)dst;
	i = -1;
	if (dst && src && dst > src)
		while (len--)
			dest[len] = source[len];
	else if (dst && src)
		while (++i < len)
			dest[i] = source[i];
	return (dst);
}
