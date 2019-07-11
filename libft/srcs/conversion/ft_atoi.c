/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:32:03 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 15:38:39 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lim(unsigned long long n, int sign)
{
	if (n >= LLMAX && sign == 0)
		return (-1);
	if (n >= LLMAX + 1 && sign == 1)
		return (0);
	return (42);
}

int			ft_atoi(const char *str)
{
	int					i;
	int					negative;
	unsigned long long	result;

	i = 0;
	negative = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			negative = 1;
	while (ft_isdigit((int)str[i]))
		result = result * 10 + ((int)str[i++] - '0');
	if (lim(result, negative) == 0 || lim(result, negative) == -1)
		return (lim(result, negative));
	return ((negative == 1) ? -result : result);
}
