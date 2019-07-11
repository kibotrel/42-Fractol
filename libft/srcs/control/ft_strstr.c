/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:16:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 16:07:42 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	if (!(size = ft_strlen(needle)))
		return ((char*)haystack);
	while (haystack[++i])
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (j == size - 1)
				return ((char*)(haystack + i));
			j++;
		}
	}
	return (NULL);
}
