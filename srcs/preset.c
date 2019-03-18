/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 01:54:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/16 06:03:32 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	mandelbrot_julia_color(t_env *env)
{
	env->palette[0] = JULIABROT_0;
	env->palette[1] = JULIABROT_1;
	env->palette[2] = JULIABROT_2;
	env->palette[3] = JULIABROT_3;
	env->palette[4] = JULIABROT_4;
	env->palette[5] = JULIABROT_5;
	env->palette[6] = JULIABROT_6;
	env->palette[7] = JULIABROT_7;
	env->palette[8] = JULIABROT_8;
	env->palette[9] = JULIABROT_9;
	env->palette[10] = JULIABROT_10;
	env->palette[11] = JULIABROT_11;
	env->palette[12] = JULIABROT_12;
	env->palette[13] = JULIABROT_13;
	env->palette[14] = JULIABROT_14;
	env->palette[15] = JULIABROT_15;
}
