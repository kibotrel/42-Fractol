/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:04:46 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 16:21:34 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

void	main_menu_infos(void *id, void *win, int status)
{
	if (!status)
		mlx_string_put(id, win, 670, 38, WHITE, "Main menu");
	mlx_string_put(id, win, 630, 138, WHITE, "Fractal selection");
	mlx_string_put(id, win, 675, 388, WHITE, "Settings");
	mlx_string_put(id, win, 640, 638, WHITE, "Quit visualizer");
}

void	selection_menu_infos(void *id, void *win, int status)
{
	if (!status)
		mlx_string_put(id, win, 620, 38, WHITE, "Fractal selection");
	mlx_string_put(id, win, 655, 155, WHITE, "Mandelbrot");
	mlx_string_put(id, win, 680, 230, WHITE, "Julia");
	mlx_string_put(id, win, 645, 305, WHITE, "Burning Ship");
	mlx_string_put(id, win, 640, 380, WHITE, "Burning Julia");
	mlx_string_put(id, win, 655, 455, WHITE, "Sierpinski");
	mlx_string_put(id, win, 685, 530, WHITE, "Koch");
	mlx_string_put(id, win, 665, 605, WHITE, "Barnsley");
	mlx_string_put(id, win, 675, 680, WHITE, "Flower");
	mlx_string_put(id, win, 1100, 750, WHITE, "Back");
}

void	settings_menu_infos(void *id, void *win, int status, t_menu m)
{
	if (!status)
	{
		mlx_string_put(id, win, 675, 38, WHITE, "Settings");
		mlx_string_put(id, win, 400, 200, WHITE, "Details level    :");
		mlx_string_put(id, win, 400, 300, WHITE, "Color mode       :");
		mlx_string_put(id, win, 400, 400, WHITE, "Gradient color   :");
		mlx_string_put(id, win, 400, 500, WHITE, "Color palette    :");
		mlx_string_put(id, win, 400, 600, WHITE, "Sound            :");
	}
	mlx_string_put(id, win, 675, 200, WHITE, "50");
	mlx_string_put(id, win, 850, 200, WHITE, "100");
	mlx_string_put(id, win, 1000, 200, WHITE, "500");
	mlx_string_put(id, win, 675, 300, WHITE, "Gradient");
	mlx_string_put(id, win, 850, 300, WHITE, "Areas");
	mlx_string_put(id, win, 675, 400, WHITE, "Default");
	mlx_string_put(id, win, 850, 400, WHITE, "Blue");
	mlx_string_put(id, win, 1000, 400, WHITE, "Red");
	mlx_string_put(id, win, 675, 500, WHITE, "Pastel");
	mlx_string_put(id, win, 850, 500, WHITE, "Fire");
	mlx_string_put(id, win, 1000, 500, WHITE, "Forest");
	mlx_string_put(id, win, 675, 600, WHITE, "Default");
	mlx_string_put(id, win, 850, 600, WHITE, "Psy");
	mlx_string_put(id, win, 1000, 600, WHITE, "Zen");
	mlx_string_put(id, win, 1100, 750, WHITE, "Back");
	color_selected_settings(id, win, m);
}
