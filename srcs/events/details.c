/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:17:18 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/26 14:10:28 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	details(t_env *env, int key)
{
	if (env->fractal == SIERPINSKI || env->fractal == KOCH)
	{
		new_img(env);
		if (key == PG_UP && env->fractal == SIERPINSKI && env->checks < 13)
			env->checks++;
		else if (key == PG_DOWN && env->fractal == SIERPINSKI && env->checks >= 1)
			env->checks--;
		else if (key == PG_UP && env->fractal == KOCH && env->checks < 10)
			env->checks++;
		else if (key == PG_DOWN && env->fractal == KOCH && env->checks >= 1)
			env->checks--;
		draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
	else
	{
		if (key == PG_UP && env->fractal == BARNSLEY && env->checks < MAX_GEN)
			env->checks += 5000;
		else if (key == PG_DOWN && env->fractal == BARNSLEY && env->checks > MIN_GEN)
		{
			env->checks -= 5000;
			new_img(env);
		}
		else if (key == PG_UP && env->checks <= MAX_LOOPS && env->fractal != BARNSLEY)
			env->checks += 5;
		else if (key == PG_DOWN && env->checks >= 20 && env->fractal != BARNSLEY)
			env->checks -= 5;
		draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
}
