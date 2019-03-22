/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 05:15:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/22 02:11:23 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "env.h"
#include "fractol.h"

static void	infos_area(t_env *env, void *id, void *win)
{
	if (env->fractal != SIERPINSKI && env->fractal != KOCH)
	{
		mlx_string_put(id, win, 955, 200, WHITE, "Color palette :");
		if (env->cam->shift == DEFAULT)
			mlx_string_put(id, win, 1115, 200, WHITE, "Default");
		else if (env->cam->shift == PASTEL)
			mlx_string_put(id, win, 1115, 200, WHITE, "Pastel");
		else if (env->cam->shift == RED_ORANGE)
			mlx_string_put(id, win, 1115, 200, WHITE, "Fire");
		else
			mlx_string_put(id, win, 1115, 200, WHITE, "Forest");
	}
}

static void	infos_gradient(t_env *env, void *id, void *win)
{
	mlx_string_put(id, win, 955, 200, WHITE, "Color shade   :");
	if (env->base_color == BLACK || env->base_color == WHITE)
		mlx_string_put(id, win, 1115, 200, WHITE, "Default");
	if (env->base_color == BLUE)
		mlx_string_put(id, win, 1115, 200, WHITE, "Blue");
	if (env->base_color == RED)
		mlx_string_put(id, win, 1115, 200, WHITE, "Red");
}

void		infos_color(t_env *env, void *id, void *win)
{
	mlx_string_put(id, win, 955, 180, WHITE, "Color mode    :");
	if (env->cam->color == GRADIENT)
		mlx_string_put(id, win, 1115, 180, WHITE, "Gradient");
	else
		mlx_string_put(id, win, 1115, 180, WHITE, "Areas");
	if (env->cam->color == AREA)
		infos_area(env, env->mlx->id, env->mlx->win);
	else
		infos_gradient(env, env->mlx->id, env->mlx->win);
}
