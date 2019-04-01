/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:55:48 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 16:07:11 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	click_sound_settings(int x, t_env *env)
{
	int	tmp;

	tmp = env->menu.sound;
	if (x >= 650 && x <= 750)
		env->menu.sound = 0;
	else if (x >= 825 && x <= 925)
		env->menu.sound = 1;
	else if (x >= 950 && x <= 1075)
		env->menu.sound = 2;
	if (tmp != env->menu.sound)
		menu(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}

void	click_details_settings(int x, t_env *env)
{
	int	tmp;

	tmp = env->menu.checks;
	if (x >= 650 && x <= 750)
		env->menu.checks = 50;
	else if (x >= 825 && x <= 925)
		env->menu.checks = 100;
	else if (x >= 950 && x <= 1050)
		env->menu.checks = 500;
	if (tmp != env->menu.checks)
		menu(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}

void	click_color_settings(int x, int y, t_env *env)
{
	int	tmp[3];

	tmp[0] = env->menu.colormode;
	tmp[1] = env->menu.base_color;
	tmp[2] = env->menu.palette;
	if (y >= 285 && y <= 335 && x >= 650 && x <= 750)
		env->menu.colormode = GRADIENT;
	else if (y >= 285 && y <= 335 && x >= 825 && x <= 925)
		env->menu.colormode = AREA;
	else if (y >= 385 && y <= 435 && x >= 650 && x <= 750)
		env->menu.base_color = DEFAULT;
	else if (y >= 385 && y <= 435 && x >= 825 && x <= 925)
		env->menu.base_color = BLUE;
	else if (y >= 385 && y <= 435 && x >= 950 && x <= 1050)
		env->menu.base_color = RED;
	else if (y >= 485 && y <= 535 && x >= 650 && x <= 750)
		env->menu.palette = PASTEL;
	else if (y >= 485 && y <= 535 && x >= 825 && x <= 925)
		env->menu.palette = RED_ORANGE;
	else if (y >= 485 && y <= 535 && x >= 950 && x <= 1075)
		env->menu.palette = FOREST;
	if (tmp[0] != env->menu.colormode
		|| tmp[1] != env->menu.base_color
		|| tmp[2] != env->menu.palette)
		menu(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}
