/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:05:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/01 18:55:58 by kibotrel         ###   ########.fr       */
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
	red = light((BLUE >> 16) & 0xFF, (WHITE >> 16) & 0xFF, percent);
	green = light((BLUE >> 8) & 0xFF, (WHITE >> 8) & 0xFF, percent);
	blue = light(BLUE & 0xFF, WHITE & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

void			color_mode(t_env *env)
{
	new_img(env);
	env->cam->color *= -1;
	draw_fractal(env);
}

// void			colorset(t_env *env, int key)
// {
// 	env = new_img(env);
// 	if (key == Z)
// 		earth_set(env);
// 	if (key == X)
// 		mars_set(env);
// 	if (key == C)
// 		moon_set(env);
//}
