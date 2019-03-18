/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 08:48:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 07:05:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	change_sound(t_env *env, int key)
{
	new_img(env);
	if (key == J)
		env->sound_name = "sound.wav";
	else if (key == K)
		env->sound_name = "sound2.wav";
	else if (key == L)
		env->sound_name = "sound3.wav";
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}

void	keyboard_zoom(t_env *env, int key)
{
	new_img(env);
	if (key == PLUS)
	{
		env->zoom_count++;
		env->cam->zoom *= 1.1;
	}
	else if (key == MINUS && env->zoom_count > 1)
	{
		env->zoom_count--;
		if ((env->cam->zoom /= 1.1) < 1)
			env->cam->zoom = 1;
	}
	update_bounds(env);
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
