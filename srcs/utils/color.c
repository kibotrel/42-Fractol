/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:45:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/22 01:54:34 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

static int	light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int			color(t_par data, t_env *env)
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

void		set1(t_env *env)
{
	env->cam->shift = PASTEL;
	env->palette[0] = PASTEL_0;
	env->palette[1] = PASTEL_1;
	env->palette[2] = PASTEL_2;
	env->palette[3] = PASTEL_3;
	env->palette[4] = PASTEL_4;
}

void		set2(t_env *env)
{
	env->cam->shift = RED_ORANGE;
	env->palette[0] = RED_ORANGE_0;
	env->palette[1] = RED_ORANGE_1;
	env->palette[2] = RED_ORANGE_2;
	env->palette[3] = RED_ORANGE_3;
	env->palette[4] = RED_ORANGE_4;
}

void		set3(t_env *env)
{
	env->cam->shift = FOREST;
	env->palette[0] = FOREST_0;
	env->palette[1] = FOREST_1;
	env->palette[2] = FOREST_2;
	env->palette[3] = FOREST_3;
	env->palette[4] = FOREST_4;
}
