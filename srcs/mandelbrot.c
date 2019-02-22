/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:18:30 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/22 19:59:43 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "fractol.h"

void	mandelbrot(t_env *env)
{
	t_par	params;

	params.y = -1;
	while (++params.y < HEIGHT)
	{
		params.x = -1;
		while (++params.x < WIDTH)
		{
			params.n = -1;
			params.cur_y = map(params.y, fill_params(0, HEIGHT, -2.0, 2.0));
			params.cur_x = map(params.x, fill_params(0, HEIGHT, -2.0, 2.0));
			params.strt_y = params.cur_y;
			params.strt_x = params.cur_x;
			while (fabs(params.cur_y + params.cur_x) < 16.0 && ++params.n < 100)
			{
				params.z_x = pow2(params.cur_y) - pow2(params.cur_x);
				params.z_y = 2 * params.cur_y * params.cur_x;
				params.cur_y = params.z_x + params.strt_y;
				params.cur_x = params.z_y + params.strt_x;
			}
			if (params.n == 100)
				pixel_to_image(env, params.y, params.x, 0x000000);
			else
				pixel_to_image(env, params.y, params.x, map(params.n, (fill_params(0, 100, 0, 255))));
		}
	}
}
