/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_menu_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:43:00 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 14:03:27 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	set_menu_params(t_env *env)
{
	env->menu.sound = DEFAULT;
	env->menu.checks = 50;
	env->menu.fractal = MENU;
	env->menu.palette = DEFAULT;
	env->menu.colormode = GRADIENT;
	env->menu.base_color = DEFAULT;
}
