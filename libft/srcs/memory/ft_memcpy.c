/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:03:09 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 15:47:34 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s2;
	size_t		i;
	const char	*s1;

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
