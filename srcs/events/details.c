/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:17:18 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/21 21:12:10 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	details(t_env *env, int key)
{
	if (env->fractal == SIERPINSKI)
		new_img(env);
	if (key == PG_UP && env->fractal != SIERPINSKI && env->checks <= MAX_LOOPS)
		env->checks += 5;
	else if (key == PG_DOWN && env->fractal != SIERPINSKI && env->checks >= 20)
		env->checks -= 5;
	else if (key == PG_UP && env->fractal == SIERPINSKI && env->checks < 14)
		env->checks++;
	else if (key == PG_DOWN && env->fractal == SIERPINSKI && env->checks >= 1)
		env->checks--;
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
