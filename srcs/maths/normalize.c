/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:32:00 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 17:19:45 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_map	fill_data(double start, double end, double min, double max)
{
	t_map	tmp;

	tmp.in_s = start;
	tmp.in_e = end;
	tmp.out_s = min;
	tmp.out_e = max;
	return (tmp);
}

double	map(double n, t_map m)
{
	return ((n - m.in_s) / (m.in_e - m.in_s) * (m.out_e - m.out_s) + m.out_s);
}
