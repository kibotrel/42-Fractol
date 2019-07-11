/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:26:18 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 15:56:09 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s1);
	while (s2 && s2[i] && i < n)
		s1[size++] = s2[i++];
	s1[size] = '\0';
	return (s1);
}
