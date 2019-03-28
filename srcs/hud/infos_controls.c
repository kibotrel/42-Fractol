/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:10:59 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/26 17:44:04 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"

void	fractal_controls(void *id, void *win)
{
	mlx_string_put(id, win, 1065, 415, WHITE, "Controls");
	mlx_string_put(id, win, 835, 480, WHITE, "Color Modes     : M");
	mlx_string_put(id, win, 1125, 480, WHITE, "Reset View      : R");
	mlx_string_put(id, win, 835, 500, WHITE, "Offset          : W/A/S/D");
	mlx_string_put(id, win, 1125, 500, WHITE, "Zoom            : Scroll");
	mlx_string_put(id, win, 970, 560, WHITE, "Details : Page_Up/Page_Down");
	mlx_string_put(id, win, 835, 620, WHITE, "Gradient Colors : V/B/N");
	mlx_string_put(id, win, 1125, 620, WHITE, "Area Colors     : Z/X/C");
	mlx_string_put(id, win, 835, 640, WHITE, "Config Julia    : Tilde");
	mlx_string_put(id, win, 1125, 640, WHITE, "Psycho mode     : P");
	mlx_string_put(id, win, 835, 660, WHITE, "Change sound    : J/K/L");
	mlx_string_put(id, win, 1125, 660, WHITE, "Select fractal  : 1/2/3");
	mlx_string_put(id, win, 1125, 680, WHITE, "                  4/5/6");
	mlx_string_put(id, win, 1125, 700, WHITE, "                  7/8/9");
	mlx_string_put(id, win, 970, 720, WHITE, "Quit : Escape / Windowcross");
	mlx_string_put(id, win, 1200, 765, WHITE, "Fractol by kibotrel");
}
