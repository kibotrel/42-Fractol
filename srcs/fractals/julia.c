/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 03:42:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/19 15:20:42 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "fractol.h"

static void	px_setup(t_par *data, double y, double x, t_env *env)
{
	double	mix;
	double	miy;
	double	max;
	double	may;

	mix = env->x_min + x;
	miy = env->y_min + y;
	max = env->x_max + x;
	may = env->y_max + y;
	data->n = -1;
	data->cur_y = map(data->y, fill_data(0, 800, miy, may));
	data->cur_x = map(data->x, fill_data(0, 800, mix, max));
}

static void	px_iterate(t_par *data, t_env *env)
{
	data->z_x = real_part(data->cur_y, data->cur_x);
	data->z_y = imaginary_part(data->cur_y, data->cur_x);
	data->cur_y = data->z_x + env->julia_y;
	data->cur_x = data->z_y + env->julia_x;
}

void		julia(t_env *env)
{
	t_par	data;

	data.y = -1;
	while (++data.y < HEIGHT)
	{
		data.x = -1;
		while (++data.x < WIDTH)
		{
			px_setup(&data, env->cam->offset_y, env->cam->offset_x, env);
			while (mod(data.cur_y, data.cur_x) < LIM && ++data.n < env->checks)
				px_iterate(&data, env);
			if (data.n == env->checks)
				pixel_to_image(env, data.y, data.x, BLACK);
			else if (env->cam->color == 1)
				pixel_to_image(env, data.y, data.x, color(data, env));
			else if (!env->cam->shift)
				pixel_to_image(env, data.y, data.x, env->palette[data.n % 16]);
			else
				pixel_to_image(env, data.y, data.x, env->palette[data.n % 5]);
		}
	}
}
