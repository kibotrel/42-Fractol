/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:15:55 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 10:36:40 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void			color_mode(t_env *env)
{
	new_img(env);
	env->cam->color *= -1;
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
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
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
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
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
