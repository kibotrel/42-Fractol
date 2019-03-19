/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_palettes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:10:12 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/19 15:19:41 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	shift_default(t_env *env)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = env->palette[0];
	while (++i < 15)
		env->palette[i] = env->palette[i + 1];
	env->palette[i] = tmp;
}

void	shift_color(t_env *env)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = env->palette[0];
	while (++i < 4)
		env->palette[i] = env->palette[i + 1];
	env->palette[i] = tmp;
}
