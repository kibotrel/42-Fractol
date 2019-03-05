/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:09:57 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/05 03:46:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

void	color_preset(t_env *env)
{
	if (env->fractal == MANDELBROT)
		mandelbrot_color(env);
	if (env->fractal == JULIA)
		mandelbrot_color(env);
}

void	draw_fractal(t_env *env)
{
	if (env->fractal == MANDELBROT)
		mandelbrot(env);
	if (env->fractal == JULIA)
		julia(env);
	mlx_put_image_to_window(env->mlx->id, env->mlx->win, env->mlx->img->id, 0, 0);
}
