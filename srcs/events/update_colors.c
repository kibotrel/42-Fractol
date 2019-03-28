/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:15:55 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/28 01:36:13 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	color_mode(t_env *env)
{
	env->cam->color *= -1;
	threads(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}

void	colorset(t_env *env, int key)
{
	if (key == Z)
		set1(env);
	else if (key == X)
		set2(env);
	else if (key == C)
		set3(env);
	threads(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}

void	base_color(t_env *env, int key)
{
	if (env->fractal == BARNSLEY)
	{
		new_img(env);
		if (key == V)
			env->base_color = GREEN;
		else if (key == B)
			env->base_color = BLUE;
		else if (key == N)
			env->base_color = RED;
	}
	else if (key == V
		&& (env->fractal == SIERPINSKI
			|| env->fractal == KOCH
			|| env->fractal == FLOWER))
		env->base_color = WHITE;
	else if (key == V)
		env->base_color = BLACK;
	else if (key == B)
		env->base_color = BLUE;
	else if (key == N)
		env->base_color = RED;
	threads(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
