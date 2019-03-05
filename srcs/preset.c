/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 01:54:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/05 02:43:11 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	mandelbrot_color(t_env *env)
{
	env->palette[0] = MANDELBROT_0;
	env->palette[1] = MANDELBROT_1;
	env->palette[2] = MANDELBROT_2;
	env->palette[3] = MANDELBROT_3;
	env->palette[4] = MANDELBROT_4;
	env->palette[5] = MANDELBROT_5;
	env->palette[6] = MANDELBROT_6;
	env->palette[7] = MANDELBROT_7;
	env->palette[8] = MANDELBROT_8;
	env->palette[9] = MANDELBROT_9;
	env->palette[10] = MANDELBROT_10;
	env->palette[11] = MANDELBROT_11;
	env->palette[12] = MANDELBROT_12;
	env->palette[13] = MANDELBROT_13;
	env->palette[14] = MANDELBROT_14;
	env->palette[15] = MANDELBROT_15;
}
