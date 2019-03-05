/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 22:22:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/05 07:57:30 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void			set1(t_env *env)
{
	env->cam->shift = NEON;
	env->palette[0] = NEON_0;
	env->palette[1] = NEON_1;
	env->palette[2] = NEON_2;
	env->palette[3] = NEON_3;
	env->palette[4] = NEON_4;
}

void			set2(t_env *env)
{
	env->cam->shift = RED_ORANGE;
	env->palette[0] = RED_ORANGE_0;
	env->palette[1] = RED_ORANGE_1;
	env->palette[2] = RED_ORANGE_2;
	env->palette[3] = RED_ORANGE_3;
	env->palette[4] = RED_ORANGE_4;
}

void			set3(t_env *env)
{
	env->cam->shift = FACEBOOK;
	env->palette[0] = FACEBOOK_0;
	env->palette[1] = FACEBOOK_1;
	env->palette[2] = FACEBOOK_2;
	env->palette[3] = FACEBOOK_3;
	env->palette[4] = FACEBOOK_4;
}