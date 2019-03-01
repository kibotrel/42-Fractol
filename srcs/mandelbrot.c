/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:18:30 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/01 21:21:15 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "fractol.h"

static void		px_setup(t_par *data, double y, double x)
{
	data->n = -1;
	data->cur_y = map(data->y, fill_data(0.0, HEIGHT, (-2.0 + y), (2.0 + y)));
	data->cur_x = map(data->x, fill_data(0.0, WIDTH, (-2.0 + x), (2.0 + x)));
	data->strt_y = data->cur_y;
	data->strt_x = data->cur_x;
}

static void		px_iterate(t_par *data)
{
	data->z_x = real_part(data->cur_y, data->cur_x);
	data->z_y = imaginary_part(data->cur_y, data->cur_x);
	data->cur_y = data->z_x + data->strt_y;
	data->cur_x = data->z_y + data->strt_x;
}
void			mandelbrot(t_env *env)
{
	t_par	data;

	data.y = -1;
	while (++data.y < HEIGHT)
	{
		data.x = -1;
		while (++data.x < WIDTH)
		{
			px_setup(&data, env->cam->offset_y, env->cam->offset_x);
			while (mod(data.cur_y, data.cur_x) < LIM && ++data.n < env->checks)
				px_iterate(&data);
			if (data.n == env->checks)
				pixel_to_image(env, data.y, data.x, BLACK);
			else if (env->cam->color == 1)
				pixel_to_image(env, data.y, data.x, color(data, env));
			else
				pixel_to_image(env, data.y, data.x, env->palette[data.n % 16]);
		}
	}
}
