/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:28:43 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/30 18:24:31 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "mlx.h"
#include "env.h"
#include "fractol.h"

static int	mouse_press(int button, int x, int y, t_env *env)
{
	if (env->fractal != MENU)
		fractal_mouse_press(button, x, y, env);
	else
		menu_mouse_press(button, x, y, env);
	return (0);
}

static int	mouse_move(int x, int y, t_env *env)
{
	if (env->fractal != MENU)
		fractal_mouse_move(x, y, env);
	else
		menu_mouse_move(x, y, env);
	return (0);
}

static int	key_press(int key, t_env *env)
{
	if (key == ESC)
		red_cross(env);
	else if (env->fractal != MENU)
		fractal_key_press(key, env);
	return (0);
}

static int	key_release(int key, t_env *env)
{
	if (key == P && env->child > 0)
	{
		kill(env->child, SIGTERM);
		kill_process_id(env->sound_name, env);
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
