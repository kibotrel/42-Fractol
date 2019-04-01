/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hover_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:55:48 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 15:44:13 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

void	hover_sound_settings(int x, t_mlx *mlx, t_menu menu)
{
	if (x >= 650 && x <= 750)
		mlx_string_put(mlx->id, mlx->win, 675, 600, TRUE_RED, "Default");
	else if (x >= 825 && x <= 925)
		mlx_string_put(mlx->id, mlx->win, 850, 600, TRUE_RED, "Psy");
	else if (x >= 950 && x <= 1075)
		mlx_string_put(mlx->id, mlx->win, 1000, 600, TRUE_RED, "Zen");
	else
		settings_menu_infos(mlx->id, mlx->win, 1, menu);
}

void	hover_details_settings(int x, t_mlx *mlx, t_menu menu)
{
	if (x >= 650 && x <= 750)
		mlx_string_put(mlx->id, mlx->win, 675, 200, TRUE_RED, "50");
	else if (x >= 825 && x <= 925)
		mlx_string_put(mlx->id, mlx->win, 850, 200, TRUE_RED, "100");
	else if (x >= 950 && x <= 1050)
		mlx_string_put(mlx->id, mlx->win, 1000, 200, TRUE_RED, "500");
	else
		settings_menu_infos(mlx->id, mlx->win, 1, menu);
}

void	hover_color_settings(int x, int y, t_mlx *mlx, t_menu menu)
{
	if (y >= 285 && y <= 335 && x >= 650 && x <= 750)
		mlx_string_put(mlx->id, mlx->win, 675, 300, TRUE_RED, "Gradient");
	else if (y >= 285 && y <= 335 && x >= 825 && x <= 925)
		mlx_string_put(mlx->id, mlx->win, 850, 300, TRUE_RED, "Areas");
	else if (y >= 385 && y <= 435 && x >= 650 && x <= 750)
		mlx_string_put(mlx->id, mlx->win, 675, 400, TRUE_RED, "Default");
	else if (y >= 385 && y <= 435 && x >= 825 && x <= 925)
		mlx_string_put(mlx->id, mlx->win, 850, 400, TRUE_RED, "Blue");
	else if (y >= 385 && y <= 435 && x >= 950 && x <= 1050)
		mlx_string_put(mlx->id, mlx->win, 1000, 400, TRUE_RED, "Red");
	else if (y >= 485 && y <= 535 && x >= 650 && x <= 750)
		mlx_string_put(mlx->id, mlx->win, 675, 500, TRUE_RED, "Pastel");
	else if (y >= 485 && y <= 535 && x >= 825 && x <= 925)
		mlx_string_put(mlx->id, mlx->win, 850, 500, TRUE_RED, "Fire");
	else if (y >= 485 && y <= 535 && x >= 950 && x <= 1075)
		mlx_string_put(mlx->id, mlx->win, 1000, 500, TRUE_RED, "Forest");
	else
		settings_menu_infos(mlx->id, mlx->win, 1, menu);
}
