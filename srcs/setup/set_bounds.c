/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 08:42:14 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/26 08:46:06 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	set_bounds(t_env *env)
{
	if (env->fractal == BARNSLEY)
	{
		env->y_min = 0;
		env->y_max = 9.9983;
		env->x_min = -2.1820;
		env->x_max = 2.6558;
	}
	else
	{
		env->y_max = 2;
		env->y_min = -2;
		env->x_max = 2;
		env->x_min = -2;
	}
}
