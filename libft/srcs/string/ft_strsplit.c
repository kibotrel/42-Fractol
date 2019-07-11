/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:14:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/05/01 12:06:47 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_split(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if (!s || !(tab = (char**)malloc(sizeof(*tab) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if (!(tab[j++] = ft_strsub(s, i, ft_wordlength(s, i, c))))
			{
				free_split(tab);
				return (NULL);
			}
			i += ft_wordlength(s, i, c);
		}
	}
	tab[j] = 0;
	return (tab);
}
