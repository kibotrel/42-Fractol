/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:57:29 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 11:59:47 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	reset(t_env *env)
{
	new_img(env);
	set_checks(env);
	env->cam->offset_y = 0.0;
	env->cam->offset_x = 0.0;
	env->y_max = 2;
	env->y_min = -2;
	env->x_max = 2;
	env->x_min = -2;
	env->zoom_count = 1;
	env->cam->zoom = 1;
	env->julia_x = 0;
	env->julia_y = 0;
	if (env->cam->shift == PASTEL)
		set1(env);
	else if (env->cam->shift == RED_ORANGE)
		set2(env);
	else if (env->cam->shift == FOREST)
		set3(env);
	else
		color_preset(env);
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
