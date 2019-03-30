/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_menu_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:43:00 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/30 20:01:02 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	set_menu_params(t_env *env)
{
	env->menu.sound = 0;
	env->menu.checks = 0;
	env->menu.fractal = 10;
	env->menu.palette = 0;
	env->menu.colormode = 0;
	env->menu.base_color = 0;
}
