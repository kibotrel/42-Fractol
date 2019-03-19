/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:32:00 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 09:47:22 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

t_map		fill_data(double start, double end, double min, double max)
{
	t_map	tmp;

	tmp.in_s = start;
	tmp.in_e = end;
	tmp.out_s = min;
	tmp.out_e = max;
	return (tmp);
}

double		map(double n, t_map m)
{
	return ((n - m.in_s) / (m.in_e - m.in_s) * (m.out_e - m.out_s) + m.out_s);
}
