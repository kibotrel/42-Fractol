/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:45:35 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 14:16:52 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	menu_mouse_move(int x, int y, t_env *env)
{
	if (env->menu_window == MAIN)
		main_menu_animations(x, y, env->mlx->id, env->mlx->win);
	else if (env->menu_window == SELECTION)
		selection_menu_animations(x, y, env->mlx->id, env->mlx->win);
	else if (env->menu_window == SETTINGS)
		settings_menu_animations(x, y, env->mlx, env->menu);
}

void	menu_mouse_press(int button, int x, int y, t_env *env)
{
	if (env->menu_window == MAIN && button == LEFT_CLICK)
		main_menu_interactions(x, y, env);
	else if (env->menu_window == SELECTION && button == LEFT_CLICK)
		selection_menu_interactions(x, y, env);
	else if (env->menu_window == SETTINGS && button == LEFT_CLICK)
		settings_menu_interactions(x, y, env);
	if (env->menu.fractal != MENU)
	{
		new_img(env);
		env->fractal = env->menu.fractal;
		env->cam->color = (env->fractal < SIERPINSKI ? env->menu.colormode : 1);
		set_fractal_params(env);
		set_bounds(env);
		fractal_to_window(env);
	}
}
