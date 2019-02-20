/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:14:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/01/16 01:59:20 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if (!s || !(tab = (char**)malloc(sizeof(*tab) * (ft_word_count(s, c) + 1))))
		return (0);
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			tab[j++] = ft_strsub(s, i, ft_word_length(s, i, c));
			i += ft_word_length(s, i, c);
		}
	}
	tab[j] = 0;
	return (tab);
}
