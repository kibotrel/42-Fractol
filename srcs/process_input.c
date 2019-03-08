/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:30:56 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/08 05:23:16 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "env.h"
#include "fractol.h"

void	offset(t_env *env, int key)
{
	new_img(env);
	if (key == W)
		env->cam->offset_x += OFFSET;
	if (key == A)
		env->cam->offset_y += OFFSET;
	if (key == S)
		env->cam->offset_x -= OFFSET;
	if (key == D)
		env->cam->offset_y -= OFFSET;
	draw_fractal(env);
}

void	details(t_env *env, int key)
{
	new_img(env);
	if (key == PG_UP)
		env->checks += 10;
	if (key == PG_DOWN && env->checks >= 20)
		env->checks -= 10;
	draw_fractal(env);
}

void	psycho_effect(t_env *env)
{
	if (!env->child)
		env->child = fork();
	if (env->child > 0)
	{
		new_img(env);
		if (!env->cam->shift)
			shift_default(env);
		else
			shift_color(env);
		draw_fractal(env);
	}
	else if (env->child == 0)
		while (1)
			system("afplay -q 1 sound.wav");
}

void	reset(t_env *env)
{
	new_img(env);
	env->checks = 100;
	env->cam->offset_y = 0.0;
	env->cam->offset_x = 0.0;
	if (env->cam->shift == NEON)
		set1(env);
	else if (env->cam->shift == RED_ORANGE)
		set2(env);
	else if (env->cam->shift == FACEBOOK)
		set3(env);
	else
		color_preset(env);
	draw_fractal(env);
}
