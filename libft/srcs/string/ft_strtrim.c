/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:22:57 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 16:09:03 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	precheck(char const *s)
{
	size_t	i;

	i = -1;
	while (s && s[++i])
		if (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (1);
	return (0);
}

static char		*blank(void)
{
	char	*empty;

	if (!(empty = (char*)malloc(sizeof(*empty * 1))))
		return (0);
	*empty = '\0';
	return (empty);
}

char			*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	i;
	size_t	end;
	size_t	start;

	end = 0;
	start = 0;
	i = 0;
	if (!precheck(s))
		return (blank());
	while (s[end])
		end++;
	while (s[end] == '\0' || s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (!s || !(trim = (char*)malloc(sizeof(*trim) * (end - start + 2))))
		return (0);
	while (start <= end)
		trim[i++] = s[start++];
	trim[i] = '\0';
	return (trim);
}
