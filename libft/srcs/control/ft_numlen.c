/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:24:36 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 14:18:57 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_numlen(long value, int base)
{
	int	size;

	size = 1;
	if (base != 10 && value < 0)
		value = -value;
	if (value < 0)
		size++;
	while (value / base)
	{
		size++;
		value /= base;
	}
	return (size);
}
