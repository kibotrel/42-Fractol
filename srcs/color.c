/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:05:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/05 03:56:05 by kibotrel         ###   ########.fr       */
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

void			color_mode(t_env *env)
{
	new_img(env);
	env->cam->color *= -1;
	draw_fractal(env);
}

void			colorset(t_env *env, int key)
{
	new_img(env);
	if (key == Z)
		set1(env);
	if (key == X)
		set2(env);
	if (key == C)
		set3(env);
	draw_fractal(env);
}

void			base_color(t_env *env, int key)
{
	new_img(env);
	if (key == V)
		env->base_color = BLACK;
	if (key == B)
		env->base_color = BLUE;
	if (key == N)
		env->base_color = RED;
	draw_fractal(env);
}
