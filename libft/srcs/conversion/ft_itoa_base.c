/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:52:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 15:45:29 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	int				size;
	long			nbr;
	char			*result;
	char			*ref_base;

	nbr = value;
	ref_base = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_numlen(nbr, base);
	if (!(result = (char*)malloc(sizeof(*result) * (size + 1))))
		return (NULL);
	result[size--] = '\0';
	result[0] = (value < 0 ? '-' : '0');
	if (value < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		result[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (result);
}
