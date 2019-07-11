/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:19:42 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/25 17:37:52 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*set;
	size_t	i;

	i = -1;
	set = (char *)b;
	while (b && len && ++i < len)
		set[i] = (unsigned char)c;
	return (b);
}
