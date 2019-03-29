/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:15:09 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/29 16:43:20 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	set_checks(t_env *env)
{
	if (env->fractal == MANDELBROT)
		env->checks = 15;
	else if (env->fractal == JULIA || env->fractal == BURNING_JULIA)
		env->checks = 25;
	else if (env->fractal == BURNING_SHIP)
		env->checks = 20;
	else if (env->fractal == SIERPINSKI
		|| env->fractal == KOCH
		|| env->fractal == FLOWER)
		env->checks = 0;
	else if (env->fractal == BARNSLEY)
		env->checks = 5000;
}
