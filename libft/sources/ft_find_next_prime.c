/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 22:24:54 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/15 18:45:01 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_next_prime(int nb)
{
	int x;

	x = nb;
	if (nb <= 2)
		return (2);
	while (x < 2 * nb)
	{
		if (ft_is_prime(x) == 1)
			return (x);
		x++;
	}
	return (0);
}
