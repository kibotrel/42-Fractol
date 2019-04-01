/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:07:57 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 17:10:31 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	change_fractal(t_env *env, int key)
{
	if (key == NUM_1)
		env->fractal = MANDELBROT;
	else if (key == NUM_2)
		env->fractal = JULIA;
	else if (key == NUM_3)
		env->fractal = BURNING_SHIP;
	else if (key == NUM_4)
		env->fractal = BURNING_JULIA;
	else if (key == NUM_5)
		env->fractal = SIERPINSKI;
	else if (key == NUM_6)
		env->fractal = KOCH;
	else if (key == NUM_7)
		env->fractal = BARNSLEY;
	else if (key == NUM_8)
		env->fractal = FLOWER;
	env->cam->shift = DEFAULT;
	color_preset(env);
	reset(env);
}
