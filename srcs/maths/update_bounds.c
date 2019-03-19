/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bounds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:35:38 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/19 15:22:38 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_bounds(t_env *env)
{
	env->y_min = -2 / env->cam->zoom;
	env->y_max = env->y_min + (4 / env->cam->zoom);
	env->x_min = -2 / env->cam->zoom;
	env->x_max = env->x_min + (4 / env->cam->zoom);
}
