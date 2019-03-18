/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:09:57 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 07:07:38 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

void	color_preset(t_env *env)
{
	if (env->fractal == MANDELBROT
		|| env->fractal == JULIA
		|| env->fractal == BURNING_JULIA)
		mandelbrot_julia_color(env);
}

void	set_checks(t_env *env)
{
	if (env->fractal == MANDELBROT)
		env->checks = 15;
	else if (env->fractal == JULIA || env->fractal == BURNING_JULIA)
		env->checks = 25;
	else if (env->fractal == BURNING_SHIP)
		env->checks = 20;
	else if (env->fractal == SIERPINSKI)
		env->checks = 0;
}

void	change_fractal(t_env *env, int key)
{
	if (key == NUM_1)
		env->fractal = MANDELBROT;
	else if (key == NUM_2)
		env->fractal = JULIA;
	else if (key == NUM_3)
		env->fractal = BURNING_SHIP;
	else if (key == NUM_4)
		env->fractal = BURNING_JULIA;
	else if (key == NUM_5)
		env->fractal = SIERPINSKI;
	env->cam->shift = DEFAULT;
	color_preset(env);
	reset(env);
}

void	draw_fractal(t_env *env, void *id, void *win, void *img)
{
	if (env->fractal == MANDELBROT)
		mandelbrot(env);
	else if (env->fractal == JULIA)
		julia(env);
	else if (env->fractal == BURNING_SHIP)
		burning_ship(env);
	else if (env->fractal == BURNING_JULIA)
		burning_julia(env);
	else if (env->fractal == SIERPINSKI)
		sierpinski(env);
	hud_background(env);
	mlx_put_image_to_window(id, win, img, 0, 0);
	hud_infos(env);
}
