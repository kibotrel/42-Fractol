/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractal_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:43:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 13:35:00 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	set_fractal_params(t_env *env)
{
	if (env->fractal < SIERPINSKI)
		env->checks = env->menu.checks;
	else
		set_checks(env);
	if (env->fractal < SIERPINSKI || env->menu.base_color)
		env->base_color = env->menu.base_color;
	else
		set_base_color(env);
	if (!env->menu.sound)
		env->sound_name = "sounds/default.wav";
	else if (env->menu.sound == 1)
		env->sound_name = "sounds/psy.wav";
	else
		env->sound_name = "sounds/zen.wav";
	if (env->fractal < SIERPINSKI)
	{
		if (env->menu.palette == PASTEL)
			set1(env);
		else if (env->menu.palette == RED_ORANGE)
			set2(env);
		else if (env->menu.palette == FOREST)
			set3(env);
		else
			mandelbrot_julia_color(env);
	}
}
