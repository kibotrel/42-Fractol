/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:28:43 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/01 21:11:16 by kibotrel         ###   ########.fr       */
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

static int		read_input(int key, void *env)
{
	if (key == ESC)
		red_cross(env);
	if (key == M)
		color_mode(env);
	if (key == PG_UP || key == PG_DOWN)
		details(env, key);
	// if (key == PLUS || key == MINUS)
	// 	zoom(env, key);
	 if (key == W || key == A || key == S || key == D)
		offset(env, key);
	// if (key == Z || key == X || key == C)
	// 	colorset(env, key);
	// if (key == H)
	// 	toggle_hud(env);
	return (0);
}

void			hooks(t_env *env)
{
	mlx_hook(env->mlx->win, 17, 0, red_cross, env);
	mlx_hook(env->mlx->win, 2, 0, read_input, env);
}
