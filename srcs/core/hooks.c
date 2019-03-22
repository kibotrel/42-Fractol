/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:28:43 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/22 01:48:24 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "mlx.h"
#include "env.h"
#include "fractol.h"

static int	mouse_press(int button, int x, int y, t_env *env)
{
	if (button == SCROLL_UP && env->fractal != SIERPINSKI && env->fractal != KOCH)
		zoom_mouse(ZOOM_IN, x, y, env);
	else if (button == SCROLL_DOWN && env->fractal != SIERPINSKI && env->fractal != KOCH)
		zoom_mouse(ZOOM_OUT, x, y, env);
	return (0);
}

static int	mouse_move(int x, int y, t_env *env)
{
	if ((env->fractal == JULIA || env->fractal == BURNING_JULIA)
	 	&& env->toggle_julia == 1)
	{
		if (x >= 0 && x < 400 && y >= 0 && y <= 800)
			env->julia_x = map(x, fill_data(0, 399, -1, 0));
		else if (x >= 400 && x <= 800 && y >= 0 && y <= 800)
			env->julia_x = map(x, fill_data(400, 800, 0, 1));
		if (y >= 0 && y < 400 && x >= 0 && x <= 800)
			env->julia_y = map(y, fill_data(0, 399, -1, 0));
		else if (y >= 400 && y <= 800 && x >= 0 && x <= 800)
			env->julia_y = map(y, fill_data(400, 800, 0, 1));
		draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
	return (0);
}

static int	key_press(int key, t_env *env)
{
	if (key == ESC)
		red_cross(env);
	else if (key == M && env->fractal != SIERPINSKI && env->fractal != KOCH)
		color_mode(env);
	else if (key == PG_UP || key == PG_DOWN)
		details(env, key);
	else if (key == W || key == A || key == S || key == D)
		offset(env, key);
	else if ((key == Z || key == X || key == C) && env->cam->color == AREA)
		colorset(env, key);
	else if ((key == V || key == B || key == N) && env->cam->color == GRADIENT)
		base_color(env, key);
	else if ((key == P && env->cam->color == AREA))
		psycho_effect(env);
	else if (key == R)
		reset(env);
	else if (key == TILDE)
		env->toggle_julia *= -1;
	else if (key == J || key == K || key == L)
		change_sound(env, key);
	else if (key == NUM_1 || key == NUM_2 || key == NUM_3 || key == NUM_4 || key == NUM_5 || key == NUM_6)
		change_fractal(env, key);
	else if (key == PLUS || key == MINUS)
		keyboard_zoom(env, key);
	return (0);
}

static int	key_release(int key, t_env *env)
{
	if (key == P && env->child > 0)
	{
		kill(env->child, SIGTERM);
		kill_process_id();
		env->child = 0;
	}
	return (0);
}

void		hooks(t_env *env)
{
	mlx_hook(env->mlx->win, 2, 0, key_press, env);
	mlx_hook(env->mlx->win, 3, 0, key_release, env);
	mlx_hook(env->mlx->win, 4, 0, mouse_press, env);
	mlx_hook(env->mlx->win, 6, 0, mouse_move, env);
	mlx_hook(env->mlx->win, 17, 0, red_cross, env);
}
