/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:36:54 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/25 17:56:12 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src && len && src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	if (src && len && ft_strlen(src) < len)
		while (i++ < len)
			dst[i - 1] = '\0';
	return (dst);
}
