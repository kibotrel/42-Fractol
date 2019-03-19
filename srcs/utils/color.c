/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:45:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 10:46:00 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

static int		light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int				color(t_par data, t_env *env)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	percent = ratio(0, env->checks, data.n);
	red = light((env->base_color >> 16) & 0xFF, (WHITE >> 16) & 0xFF, percent);
	green = light((env->base_color >> 8) & 0xFF, (WHITE >> 8) & 0xFF, percent);
	blue = light(env->base_color & 0xFF, WHITE & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
