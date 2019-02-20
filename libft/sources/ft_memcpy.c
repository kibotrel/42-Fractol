/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:03:09 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/25 17:32:32 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s1;
	char		*s2;
	size_t		i;

	s1 = src;
	s2 = dst;
	i = -1;
	if (dst == src)
		return (dst);
	if (n == 0)
		return (dst);
	while (dst && src && ++i < n)
		s2[i] = s1[i];
	return (dst);
}
