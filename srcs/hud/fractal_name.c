/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:58:05 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 14:58:26 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

void			get_fractal_name(void *mlx, void *win, t_env *env)
{
	if (env->fractal == MANDELBROT)
		mlx_string_put(mlx, win, 1050, 65, WHITE, "Mandelbrot");
	else if (env->fractal == JULIA)
		mlx_string_put(mlx, win, 1075, 65, WHITE, "Julia");
	else if (env->fractal == BURNING_SHIP)
		mlx_string_put(mlx, win, 1040, 65, WHITE, "Burning Ship");
	else if (env->fractal == BURNING_JULIA)
		mlx_string_put(mlx, win, 1035, 65, WHITE, "Burning Julia");
	else if (env->fractal == SIERPINSKI)
		mlx_string_put(mlx, win, 1050, 65, WHITE, "Sierpinski");
}