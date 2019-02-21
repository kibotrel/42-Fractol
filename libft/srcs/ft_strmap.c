/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:09:20 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/11 16:14:53 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	int		i;

	i = -1;
	if (!s || !(map = (char*)malloc(sizeof(*map) * (ft_strlen(s) + 1))))
		return (0);
	while (s[++i])
		map[i] = f(s[i]);
	map[i] = '\0';
	return (map);
}
