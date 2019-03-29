/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:12:22 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/29 16:41:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	zoom_mouse(int direction, double x, double y, t_env *env)
{
	if (y >= 0 && y <= 800 && x >= 0 && x <= 800)
	{
		if (direction == ZOOM_IN)
		{
			env->zoom_count++;
			if (x > 0 && x < 400)
				env->cam->offset_y -= (OFF / env->cam->zoom) * ((400 - x) / 64);
			else if (x >= 400 && x < 800)
				env->cam->offset_y += (OFF / env->cam->zoom) * ((x - 400) / 64);
			if (y > 0 && y < 400)
				env->cam->offset_x -= (OFF / env->cam->zoom) * ((400 - y) / 64);
			else if (y >= 400 && y < 800)
				env->cam->offset_x += (OFF / env->cam->zoom) * ((y - 400) / 64);
			env->cam->zoom *= 1.1;
		}
		else if (direction == ZOOM_OUT && env->zoom_count > 1)
		{
			env->zoom_count--;
			if ((env->cam->zoom /= 1.1) < 1)
				env->cam->zoom = 1;
		}
		update_bounds(env);
		threads(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
}

void	keyboard_zoom(t_env *env, int key)
{
	if (env->fractal >= SIERPINSKI)
		new_img(env);
	if (key == PLUS && env->cam->zoom < 50)
	{
		env->zoom_count++;
		env->cam->zoom *= 1.1;
	}
	else if (key == MINUS && env->zoom_count > 1)
	{
		env->zoom_count--;
		if ((env->cam->zoom /= 1.1) < 1)
			env->cam->zoom = 1;
	}
	update_bounds(env);
	threads(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
