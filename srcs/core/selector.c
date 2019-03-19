/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:09:57 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 10:08:35 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

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