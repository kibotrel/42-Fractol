/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 08:48:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 02:22:12 by kibotrel         ###   ########.fr       */
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
