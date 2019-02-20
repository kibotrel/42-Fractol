/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 23:27:32 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/16 12:29:01 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = -1;
	while (++i < length - 2)
	{
		if (f(tab[i], tab[i + 1]) > 0)
		{
			while (++i < length - 1)
			{
				if (f(tab[i], tab[i + 1]) < 0)
					return (0);
			}
		}
		else if (f(tab[i], tab[i + 1]) < 0)
		{
			while (++i < length - 1)
			{
				if (f(tab[i], tab[i + 1]) > 0)
					return (0);
			}
		}
	}
	return (1);
}
