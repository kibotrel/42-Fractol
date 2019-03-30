/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:11:23 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/30 17:37:06 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	change_sound(t_env *env, int key)
{
	if (key == J)
		env->sound_name = "sounds/default.wav";
	else if (key == K)
		env->sound_name = "sounds/psy.wav";
	else if (key == L)
		env->sound_name = "sounds/zen.wav";
	threads(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
