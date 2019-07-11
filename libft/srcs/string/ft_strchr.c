/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:09:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 15:54:21 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	if (c == 0)
		return ((char*)s + ft_strlen(s));
	while (s && s[++i])
		if (s[i] == c)
			return ((char*)s + i);
	return (NULL);
}
