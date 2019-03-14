/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:28:43 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/14 01:58:26 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "mlx.h"
#include "env.h"
#include "fractol.h"


static int		mouse_press(int	button, int x, int y, t_env *env)
{
	if (button == SCROLL_UP)
		zoom(ZOOM_IN, x, y, env);
	if (button == SCROLL_DOWN)
		zoom(ZOOM_OUT, x, y, env);
	return (0);
}
static int		mouse_move(int x, int y, t_env *env)
{
	if (env->fractal == JULIA && env->toggle_julia == 1)
	{
		new_img(env);
		if (x >= 0 && x < WIDTH / 2 && y >= 0 && y <= HEIGHT)
			env->julia_x = map(x, fill_data(0, WIDTH / 2 - 1, -1, 0));
		else if (x > WIDTH / 2 && x <= WIDTH && y >= 0 && y <= HEIGHT)
			env->julia_x = map(x, fill_data(WIDTH / 2, WIDTH, 0, 1));
		if (y >= 0 && y < HEIGHT / 2 && x >= 0 && x <= WIDTH)
			env->julia_y = map(y, fill_data(0, HEIGHT / 2 - 1, -1, 0));
		else if (y > HEIGHT / 2 && y <= HEIGHT && x >= 0 && x <= WIDTH)
			env->julia_y = map(y, fill_data(HEIGHT / 2, HEIGHT, 0, 1));
		draw_fractal(env);
	}
	return (0);
}

static int		key_press(int key, t_env *env)
{
	if (key == ESC)
		red_cross(env);
	else if (key == M)
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
	else if (key == H)
		env->cam->hud *= -1;
	// else if (key == J || key == K || key == L)
	// 	change_sound(env, key);
	return (0);
}

static int		key_release(int key, t_env *env)
{
	if (key == P && env->child > 0)
	{
		kill(env->child, SIGTERM);
		kill_process_id();
		env->child = 0;
	}
	return (0);
}

void			hooks(t_env *env)
{
	mlx_hook(env->mlx->win, 2, 0, key_press, env);
	mlx_hook(env->mlx->win, 3, 0, key_release, env);
	mlx_hook(env->mlx->win, 4, 0, mouse_press, env);
	mlx_hook(env->mlx->win, 6, 0, mouse_move, env);
	mlx_hook(env->mlx->win, 17, 0, red_cross, env);
}
