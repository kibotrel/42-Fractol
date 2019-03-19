/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:14:45 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 11:15:07 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	offset(t_env *env, int key)
{
	new_img(env);
	if (key == W && env->fractal == SIERPINSKI)
		env->cam->offset_x += 25;
	else if (key == A && env->fractal == SIERPINSKI)
		env->cam->offset_y += 25;
	else if (key == S && env->fractal == SIERPINSKI)
		env->cam->offset_x -= 25;
	else if (key == D && env->fractal == SIERPINSKI)
		env->cam->offset_y -= 25;
	else if (key == W && env->cam->offset_x < OFFSET_MAX)
		env->cam->offset_x += OFFSET / env->cam->zoom;
	else if (key == A && env->cam->offset_y < OFFSET_MAX)
		env->cam->offset_y += OFFSET / env->cam->zoom;
	else if (key == S && env->cam->offset_x > OFFSET_MIN)
		env->cam->offset_x -= OFFSET / env->cam->zoom;
	else if (key == D && env->cam->offset_y > OFFSET_MIN)
		env->cam->offset_y -= OFFSET / env->cam->zoom;
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
