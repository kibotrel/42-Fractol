/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:40:21 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/30 19:41:29 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

static void	menu_boxes(t_env *env)
{
	int	x;
	int	y;

	y = 99;
	while (++y < HEIGHT)
	{
		x = 399;
		while (++x <= 1000)
		{
			if ((y == 100 || y == 200) && (x >= 400 && x <= 1000))
				pixel_to_image(env, x, y, WHITE);
			if ((y == 350 || y == 450) && (x >= 400 && x <= 1000))
				pixel_to_image(env, x, y, WHITE);
			if ((y == 600 || y == 700) && (x >= 400 && x <= 1000))
				pixel_to_image(env, x, y, WHITE);
		}
	}
}

static void	menu_background(t_env *env)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (x <= 200 || (x >= 1200 && x <= WIDTH))
				pixel_to_image(env, x, y, DARK_GRAY);
			else
				pixel_to_image(env, x, y, LIGHT_GRAY);
		}
	}
}

static void	menu_infos(t_env *env)
{
	if (env->menu_window == MAIN)
		main_menu_infos(env->mlx->id, env->mlx->win, 0);
	if (env->menu_window == SELECTION)
		selection_menu_infos(env->mlx->id, env->mlx->win, 0);
	if (env->menu_window == SETTINGS)
		settings_menu_infos(env->mlx->id, env->mlx->win, 0);
}
void		menu(t_env *env, void *id, void *win, void *img)
{
	menu_background(env);
	if (env->menu_window == MAIN)
		menu_boxes(env);
	mlx_put_image_to_window(id, win, img, 0, 0);
	menu_infos(env);
}
