/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selected_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:45:09 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 16:59:08 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

static void	sound_settings(void *id, void *win, t_menu menu)
{
	if (!menu.sound)
		mlx_string_put(id, win, 675, 600, TRUE_RED, "Default");
	else if (menu.sound == 1)
		mlx_string_put(id, win, 850, 600, TRUE_RED, "Psy");
	else
		mlx_string_put(id, win, 1000, 600, TRUE_RED, "Zen");
}

static void	details_settings(void *id, void *win, t_menu menu)
{
	if (menu.checks == 50)
		mlx_string_put(id, win, 675, 200, TRUE_RED, "50");
	else if (menu.checks == 100)
		mlx_string_put(id, win, 850, 200, TRUE_RED, "100");
	else
		mlx_string_put(id, win, 1000, 200, TRUE_RED, "500");
}

static void	color_settings(void *id, void *win, t_menu menu)
{
	if (menu.colormode == GRADIENT)
		mlx_string_put(id, win, 675, 300, TRUE_RED, "Gradient");
	else
		mlx_string_put(id, win, 850, 300, TRUE_RED, "Areas");
	if (!menu.base_color)
		mlx_string_put(id, win, 675, 400, TRUE_RED, "Default");
	else if (menu.base_color == BLUE)
		mlx_string_put(id, win, 850, 400, TRUE_RED, "Blue");
	else
		mlx_string_put(id, win, 1000, 400, TRUE_RED, "Red");
	if (menu.palette == PASTEL)
		mlx_string_put(id, win, 675, 500, TRUE_RED, "Pastel");
	else if (menu.palette == RED_ORANGE)
		mlx_string_put(id, win, 850, 500, TRUE_RED, "Fire");
	else if (menu.palette == FOREST)
		mlx_string_put(id, win, 1000, 500, TRUE_RED, "Forest");
}

void		color_selected_settings(void *id, void *win, t_menu menu)
{
	details_settings(id, win, menu);
	color_settings(id, win, menu);
	sound_settings(id, win, menu);
}
