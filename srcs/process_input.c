/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:30:56 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/01 21:18:36 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	offset(t_env *env, int key)
{
	new_img(env);
	if (key == W)
		env->cam->offset_x += OFFSET;
	if (key == A)
		env->cam->offset_y += OFFSET;
	if (key == S)
		env->cam->offset_x -= OFFSET;
	if (key == D)
		env->cam->offset_y -= OFFSET;
	draw_fractal(env);
}

void	details(t_env *env, int key)
{
	new_img(env);
	if (key == PG_UP)
		env->checks += 10;
	if (key == PG_DOWN && env->checks >= 20)
		env->checks -= 10;
	draw_fractal(env);
}
