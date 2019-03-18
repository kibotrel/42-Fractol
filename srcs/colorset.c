/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 22:22:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 07:14:01 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	set1(t_env *env)
{
	env->cam->shift = PASTEL;
	env->palette[0] = PASTEL_0;
	env->palette[1] = PASTEL_1;
	env->palette[2] = PASTEL_2;
	env->palette[3] = PASTEL_3;
	env->palette[4] = PASTEL_4;
}

void	set2(t_env *env)
{
	env->cam->shift = RED_ORANGE;
	env->palette[0] = RED_ORANGE_0;
	env->palette[1] = RED_ORANGE_1;
	env->palette[2] = RED_ORANGE_2;
	env->palette[3] = RED_ORANGE_3;
	env->palette[4] = RED_ORANGE_4;
}

void	set3(t_env *env)
{
	env->cam->shift = FOREST;
	env->palette[0] = FOREST_0;
	env->palette[1] = FOREST_1;
	env->palette[2] = FOREST_2;
	env->palette[3] = FOREST_3;
	env->palette[4] = FOREST_4;
}

void	shift_default(t_env *env)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = env->palette[0];
	while (++i < 15)
		env->palette[i] = env->palette[i + 1];
	env->palette[i] = tmp;
}

void	shift_color(t_env *env)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = env->palette[0];
	while (++i < 4)
		env->palette[i] = env->palette[i + 1];
	env->palette[i] = tmp;
}
