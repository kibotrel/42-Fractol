/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 09:32:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/26 14:07:14 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "fractol.h"

static void	draw_point(t_posd current, t_env *env)
{
	t_posd	p;
	t_posd	min;
	t_posd	max;

	min.x = env->x_min + env->cam->offset_y;
	min.y = env->y_min - env->cam->offset_x;
	max.x = env->x_max + env->cam->offset_y;
	max.y = env->y_max - env->cam->offset_x;
	p.x = map(current.x, fill_data(min.x, max.x, 0, 800));
	p.y = map(current.y, fill_data(min.y, max.y, 800, 0));
	pixel_to_image(env, p.x, p.y, env->base_color);
}

static void	next_point(t_posd *current, int r)
{
	t_posd	next;

	if (r < 2)
	{
		next.x = 0;
		next.y = 0.16 * current->y;
	}
	else if (r < 87)
	{
		next.x = 0.85 * current->x + 0.04 * current->y;
		next.y = -0.04 * current->x + 0.85 * current->y + 1.6;
	}
	else if (r < 94)
	{
		next.x = 0.2 * current->x - 0.26 * current->y;
		next.y = 0.23 * current->x + 0.22 * current->y + 1.6;
	}
	else
	{
		next.x = -0.15 * current->x + 0.28 * current->y;
		next.y = 0.26 * current->x + 0.24 * current->y + 0.44;
	}
	current->x = next.x;
	current->y = next.y;
}

void		barnsley(t_env *env)
{
	int		i;
	t_posd	current;

	current.x = 0;
	current.y = 0;
	i = -1;
	while (++i < env->checks)
	{
		draw_point(current, env);
		next_point(&current, rand() % 101);
	}
	hud_background(env);
}
