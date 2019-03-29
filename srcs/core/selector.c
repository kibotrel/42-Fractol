/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:09:57 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/29 16:27:30 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

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
