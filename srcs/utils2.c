/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 01:23:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 02:22:28 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "env.h"
#include "fractol.h"

int		red_cross(void *env)
{
	free_all(env);
	exit(0);
	return (0);
}

void	get_fractal_name(void *mlx, void *win, t_env *env)
{
	if (env->fractal == MANDELBROT)
		mlx_string_put(mlx, win, 1050, 65, WHITE, "Mandelbrot");
	else if (env->fractal == JULIA)
		mlx_string_put(mlx, win, 1075, 65, WHITE, "Julia");
	else if (env->fractal == BURNING_SHIP)
		mlx_string_put(mlx, win, 1040, 65, WHITE, "Burning Ship");
	else if (env->fractal == BURNING_JULIA)
		mlx_string_put(mlx, win, 1035, 65, WHITE, "Burning Julia");
}

void	update_bounds(t_env *env)
{
	env->y_min = -2 / env->cam->zoom;
	env->y_max = env->y_min + (4 / env->cam->zoom);
	env->x_min = -2 / env->cam->zoom;
	env->x_max = env->x_min + (4 / env->cam->zoom);
}
