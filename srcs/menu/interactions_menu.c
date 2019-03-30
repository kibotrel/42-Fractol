/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions_menu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:06:40 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/30 19:11:00 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

void	main_menu_interactions(int x, int y, t_env *env)
{
	if (y >= 100 && y <= 200 && x >= 400 && x <= 1000)
	{
		env->menu_window = SELECTION;
		menu(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
	else if (y >= 350 && y <= 450 && x >= 400 && x <= 1000)
	{
		env->menu_window = SETTINGS;
		menu(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
	else if (y >= 600 && y <= 700 && x >= 400 && x <= 1000)
		red_cross(env);
}

void	selection_menu_interactions(int x, int y, t_env *env)
{
	if (y >= 750 && y <= 785 && x >= 1080 && x <= 1170)
	{
		env->menu_window = MAIN;
		menu(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
	else
	{
		if (y >= 140 && y <= 190 && x >= 600 && x <= 800)
			env->fractal = MANDELBROT;
		else if (y >= 215 && y <= 265 && x >= 600 && x <= 800)
			env->fractal = JULIA;
		else if (y >= 290 && y <= 340 && x >= 600 && x <= 800)
			env->fractal = BURNING_SHIP;
		else if (y >= 365 && y <= 415 && x >= 600 && x <= 800)
			env->fractal = BURNING_JULIA;
		else if (y >= 440 && y <= 490 && x >= 600 && x <= 800)
			env->fractal = SIERPINSKI;
		else if (y >= 515 && y <= 565 && x >= 600 && x <= 800)
			env->fractal = KOCH;
		else if (y >= 590 && y <= 640 && x >= 600 && x <= 800)
			env->fractal = BARNSLEY;
		else if (y >= 665 && y <= 715 && x >= 600 && x <= 800)
			env->fractal = FLOWER;
	}
}

void	settings_menu_interactions(int x, int y, t_env *env)
{
	if (y >= 750 && y <= 785 && x >= 1080 && x <= 1170)
	{
		env->menu_window = MAIN;
		menu(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
}
