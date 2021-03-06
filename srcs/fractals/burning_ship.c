/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:39:20 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/28 05:47:43 by kibotrel         ###   ########.fr       */
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
	data->strt_y = data->cur_y;
	data->strt_x = data->cur_x;
}

static void	px_iterate(t_par *data)
{
	data->z_x = real_part(data->cur_y, data->cur_x);
	data->z_y = fabs(imaginary_part(data->cur_y, data->cur_x));
	data->cur_y = fabs(data->z_x + data->strt_y);
	data->cur_x = data->z_y + data->strt_x;
}

void		burning_ship(t_env *env, int thread)
{
	t_par	data;
	int		limit;

	if (!env->cam->shift)
		set2(env);
	data.y = (thread == 0 ? 0 : thread * 25);
	limit = 25 * (thread + 1);
	while (++data.y <= limit)
	{
		data.x = -1;
		while (++data.x < 800)
		{
			px_setup(&data, env->cam->offset_y, env->cam->offset_x, env);
			while (mod(data.cur_y, data.cur_x) < LIM && ++data.n < env->checks)
				px_iterate(&data);
			if (data.n == env->checks)
				pixel_to_image(env, data.y, data.x, BLACK);
			else if (env->cam->color == 1)
				pixel_to_image(env, data.y, data.x, color(data, env));
			else
				pixel_to_image(env, data.y, data.x, env->palette[data.n % 5]);
		}
	}
}
