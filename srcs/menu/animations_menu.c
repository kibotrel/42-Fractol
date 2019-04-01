/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:07:17 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 15:44:36 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

void	main_menu_animations(int x, int y, void *id, void *win)
{
	if (y >= 100 && y <= 200 && x >= 400 && x <= 1000)
		mlx_string_put(id, win, 630, 138, TRUE_RED, "Fractal selection");
	else if (y >= 350 && y <= 450 && x >= 400 && x <= 1000)
		mlx_string_put(id, win, 675, 388, TRUE_RED, "Settings");
	else if (y >= 600 && y <= 700 && x >= 400 && x <= 1000)
		mlx_string_put(id, win, 640, 638, TRUE_RED, "Quit visualizer");
	else
		main_menu_infos(id, win, 1);
}

void	selection_menu_animations(int x, int y, void *id, void *win)
{
	if (y >= 140 && y <= 190 && x >= 600 && x <= 800)
		mlx_string_put(id, win, 655, 155, TRUE_RED, "Mandelbrot");
	else if (y >= 215 && y <= 265 && x >= 600 && x <= 800)
		mlx_string_put(id, win, 680, 230, TRUE_RED, "Julia");
	else if (y >= 290 && y <= 340 && x >= 600 && x <= 800)
		mlx_string_put(id, win, 645, 305, TRUE_RED, "Burning Ship");
	else if (y >= 365 && y <= 415 && x >= 600 && x <= 800)
		mlx_string_put(id, win, 640, 380, TRUE_RED, "Burning Julia");
	else if (y >= 440 && y <= 490 && x >= 600 && x <= 800)
		mlx_string_put(id, win, 655, 455, TRUE_RED, "Sierpinski");
	else if (y >= 515 && y <= 565 && x >= 600 && x <= 800)
		mlx_string_put(id, win, 685, 530, TRUE_RED, "Koch");
	else if (y >= 590 && y <= 640 && x >= 600 && x <= 800)
		mlx_string_put(id, win, 665, 605, TRUE_RED, "Barnsley");
	else if (y >= 665 && y <= 715 && x >= 600 && x <= 800)
		mlx_string_put(id, win, 675, 680, TRUE_RED, "Flower");
	else if (y >= 735 && y <= 785 && x >= 1000 && x <= 1200)
		mlx_string_put(id, win, 1100, 750, TRUE_RED, "Back");
	else
		selection_menu_infos(id, win, 1);
}

void	settings_menu_animations(int x, int y, t_mlx *mlx, t_menu menu)
{
	if (y >= 735 && y <= 785 && x >= 1000 && x <= 1200)
		mlx_string_put(mlx->id, mlx->win, 1100, 750, TRUE_RED, "Back");
	else if (y >= 185 && y <= 235)
		hover_details_settings(x, mlx, menu);
	else if (y >= 285 && y <= 535)
		hover_color_settings(x, y, mlx, menu);
	else if (y >= 585 && y <= 635)
		hover_sound_settings(x, mlx, menu);
	else
		settings_menu_infos(mlx->id, mlx->win, 1, menu);
}
