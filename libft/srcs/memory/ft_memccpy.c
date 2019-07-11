/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:32:13 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 15:46:17 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char				*dest;
	size_t				i;
	const unsigned char	*source;

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
