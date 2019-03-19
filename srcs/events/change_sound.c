/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:11:23 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/19 13:19:34 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	change_sound(t_env *env, int key)
{
	new_img(env);
	if (key == J)
		env->sound_name = "sounds/sound.wav";
	else if (key == K)
		env->sound_name = "sounds/sound2.wav";
	else if (key == L)
		env->sound_name = "sounds/sound3.wav";
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
