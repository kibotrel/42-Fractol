/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:24:00 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/16 14:50:11 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = -1;
	if (!(size = ft_strlen(needle)))
		return ((char*)haystack);
	while (haystack[++i] && i < n)
	{
		j = 0;
		while ((needle[j] == haystack[i + j]) && (i + j < n))
		{
			if (j == size - 1)
				return ((char*)(haystack + i));
			j++;
		}
	}
	return (NULL);
}
