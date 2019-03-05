/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:28:43 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/05 08:05:12 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "env.h"
#include "fractol.h"

static int		red_cross(void *env)
{
	free_all(env);
	exit(0);
	return (0);
}

static int		read_input(int key, t_env *env)
{
	if (key == ESC)
		red_cross(env);
	if (key == M)
		color_mode(env);
	if (key == PG_UP || key == PG_DOWN)
		details(env, key);
	if (key == W || key == A || key == S || key == D)
		offset(env, key);
	if ((key == Z || key == X || key == C) && env->cam->color == AREA)
		colorset(env, key);
	if ((key == V || key == B || key == N) && env->cam->color == GRADIENT)
		base_color(env, key);
	if ((key == P && env->cam->color == AREA))
		psycho_effect(env);
	if (key == R)
		reset(env);
	// if (key == H)
	// 	toggle_hud(env);
	return (0);
}

void			hooks(t_env *env)
{
	mlx_hook(env->mlx->win, 17, 0, red_cross, env);
	mlx_hook(env->mlx->win, 2, 0, read_input, env);
}
