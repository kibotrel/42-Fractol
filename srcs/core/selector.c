/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:09:57 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/29 18:24:20 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	fractal_to_window(t_env *env)
{
	hud_background(env);
	threads(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}

void	draw_fractal(t_env *env)
{
	if (env->fractal == SIERPINSKI)
		sierpinski(env);
	else if (env->fractal == KOCH)
		koch(env);
	else if (env->fractal == BARNSLEY)
		barnsley(env);
	else if (env->fractal == FLOWER)
		flower(env);
}
