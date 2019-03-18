/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 01:23:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 06:13:20 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "env.h"
#include "fractol.h"

int				red_cross(void *env)
{
	free_all(env);
	exit(0);
	return (0);
}

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

void			update_bounds(t_env *env)
{
	env->y_min = -2 / env->cam->zoom;
	env->y_max = env->y_min + (4 / env->cam->zoom);
	env->x_min = -2 / env->cam->zoom;
	env->x_max = env->x_min + (4 / env->cam->zoom);
}


static t_line	setup_params(t_pos a, t_pos b)
{
	t_line	params;

	params.sign_y = (a.y < b.y ? 1 : -1);
	params.sign_x = (a.x < b.x ? 1 : -1);
	params.delta_y = abs(b.y - a.y);
	params.delta_x = abs(b.x - a.x);
	params.offset = params.delta_x - params.delta_y;
	params.error = 0;
	return (params);
}

void			draw_line(t_pos a, t_pos b, t_env *env)
{
	t_line	params;
	t_pos	p;

	params = setup_params(a, b);
	p = a;
	while (p.y != b.y || p.x != b.x)
	{
		pixel_to_image(env, p.x, p.y, WHITE);
		if ((params.error = params.offset * 2) > -params.delta_y)
		{
			params.offset -= params.delta_y;
			p.x += params.sign_x;
		}
		if (params.error < params.delta_x)
		{
			params.offset += params.delta_x;
			p.y += params.sign_y;
		}
	}
	pixel_to_image(env, p.x, p.y, WHITE);
}
