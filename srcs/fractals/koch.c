/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 01:20:06 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/26 16:36:33 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

static void	depth(t_pos p[2], double a, t_env *env, int lvl)
{
	t_pos	t[3];

	t[0].x = (2 * p[0].x + p[1].x) / 3;
	t[0].y = (2 * p[0].y + p[1].y) / 3;
	t[1].x = (p[0].x + 2 * p[1].x) / 3;
	t[1].y = (p[0].y + 2 * p[1].y) / 3;
	t[2].x = t[0].x + (t[1].x - t[0].x) * cos(a) + (t[1].y - t[0].y) * sin(a);
	t[2].y = t[0].y + (t[1].x - t[0].x) * -sin(a) + (t[1].y - t[0].y) * cos(a);
	if (lvl == 0)
		draw_line(p[0], p[1], env);
	else
	{
		depth((t_pos[2]){p[0], t[0]}, a, env, lvl - 1);
		depth((t_pos[2]){t[0], t[2]}, a, env, lvl - 1);
		depth((t_pos[2]){t[2], t[1]}, a, env, lvl - 1);
		depth((t_pos[2]){t[1], p[1]}, a, env, lvl - 1);
	}
}

void		koch(t_env *env)
{
	t_pos	p[3];
	double	angle;

	angle = 60 * M_PI / 180;
	p[0].x = 75 * env->cam->zoom - env->cam->offset_y;
	p[0].y = 210 * env->cam->zoom - env->cam->offset_x;
	p[1].x = 725 * env->cam->zoom - env->cam->offset_y;
	p[1].y = 210 * env->cam->zoom - env->cam->offset_x;
	p[2].x = p[0].x + (p[1].x - p[0].x) / 2;
	p[2].y = p[0].y + sqrt(pow2(p[1].x - p[0].x) - pow2((p[1].x - p[0].x) / 2));
	depth((t_pos[2]){p[0], p[1]}, angle, env, env->checks);
	depth((t_pos[2]){p[1], p[2]}, angle, env, env->checks);
	depth((t_pos[2]){p[2], p[0]}, angle, env, env->checks);
	hud_background(env);
}
