/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:18:30 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 19:53:19 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "fractol.h"

void			mandelbrot(t_env *env)
{
	t_par	data;

	data.y = -1;
	while (++data.y < HEIGHT)
	{
		data.x = -1;
		while (++data.x < WIDTH)
		{
			data.n = -1;
			data.cur_y = map(data.y, fill_data(0.0, HEIGHT, -2.0, 2.0));
			data.cur_x = map(data.x, fill_data(0.0, WIDTH, -2.0, 2.0));
			data.strt_y = data.cur_y;
			data.strt_x = data.cur_x;
			while (mod(data.cur_y, data.cur_x) < 8 && ++data.n < env->checks)
			{
				data.z_x = real_part(data.cur_y, data.cur_x);
				data.z_y = imaginary_part(data.cur_y, data.cur_x);
				data.cur_y = data.z_x + data.strt_y;
				data.cur_x = data.z_y + data.strt_x;
			}
			if (data.n == env->checks)
				pixel_to_image(env, data.y, data.x, BLACK);
			else
				pixel_to_image(env, data.y, data.x, color(data, env));
		}
	}
}
