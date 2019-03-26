/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:14:45 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/26 12:54:37 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	offset(t_env *env, int key)
{
	if (env->fractal == SIERPINSKI || env->fractal == KOCH || env->fractal == BARNSLEY)
		new_img(env);
	if (env->fractal == SIERPINSKI || env->fractal == KOCH)
	{
		if (key == W)
			env->cam->offset_x += 25;
		else if (key == A)
			env->cam->offset_y += 25;
		else if (key == S)
			env->cam->offset_x -= 25;
		else if (key == D)
			env->cam->offset_y -= 25;
	}
	else if (env->fractal == BARNSLEY)
	{
		if (key == W)
			env->cam->offset_x += OFF / env->cam->zoom;
		else if (key == A)
			env->cam->offset_y += OFF / env->cam->zoom;
		else if (key == S)
			env->cam->offset_x -= OFF/ env->cam->zoom;
		else if (key == D)
			env->cam->offset_y -= OFF / env->cam->zoom;
	}
	else if (key == W && env->cam->offset_x < OFFSET_MAX)
		env->cam->offset_x += OFF / env->cam->zoom;
	else if (key == A && env->cam->offset_y < OFFSET_MAX)
		env->cam->offset_y += OFF / env->cam->zoom;
	else if (key == S && env->cam->offset_x > OFFSET_MIN)
		env->cam->offset_x -= OFF/ env->cam->zoom;
	else if (key == D && env->cam->offset_y > OFFSET_MIN)
		env->cam->offset_y -= OFF / env->cam->zoom;
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
