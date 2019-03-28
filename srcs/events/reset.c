/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:57:29 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/28 01:35:56 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

static void	set_default_value(t_env *env)
{
	env->cam->offset_y = 0.0;
	env->cam->offset_x = 0.0;
	set_bounds(env);
	env->zoom_count = 1;
	env->cam->zoom = 1;
	env->julia_x = 0;
	env->julia_y = 0;
}

void		reset(t_env *env)
{
	if (env->fractal >= SIERPINSKI)
		new_img(env);
	set_checks(env);
	set_default_value(env);
	set_base_color(env);
	if (env->cam->shift == PASTEL)
		set1(env);
	else if (env->cam->shift == RED_ORANGE)
		set2(env);
	else if (env->cam->shift == FOREST)
		set3(env);
	else
		color_preset(env);
	threads(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
