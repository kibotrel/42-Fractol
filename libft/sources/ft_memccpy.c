/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:32:13 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/25 17:36:02 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char				*dest;
	const unsigned char	*source;
	size_t				i;

	dest = (char*)dst;
	source = (const unsigned char*)src;
	i = -1;
	while (dst && src && ++i < n)
	{
		dest[i] = source[i];
		if (source[i] == (unsigned char)c)
			return ((void*)dest + (i + 1));
	}
	return (NULL);
}
