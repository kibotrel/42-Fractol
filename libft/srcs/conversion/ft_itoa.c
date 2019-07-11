/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:56:21 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 15:45:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_itoa(int n)
{
	int			length;
	long		nb;
	char		*str;

	nb = n;
	length = ft_numlen(nb, 10);
	if (!(str = (char*)malloc(sizeof(*str) * (length + 1))))
		return (0);
	str[length--] = '\0';
	str[0] = (n == 0 ? '0' : '-');
	if (n < 0)
		nb = -nb;
	while (nb > 0)
	{
		str[length--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
