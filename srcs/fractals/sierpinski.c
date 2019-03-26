/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 02:13:46 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/26 08:07:04 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "env.h"
#include "fractol.h"

static t_pos	mid(t_pos a, t_pos b)
{
	t_pos mid;

	mid.x = a.x + (b.x - a.x) / 2;
	mid.y = a.y + (b.y - a.y) / 2;
	return (mid);
}

static void		depth(t_pos p[3], t_env *env, int lvl)
{
	draw_line(p[0], p[1], env);
	draw_line(p[1], p[2], env);
	draw_line(p[2], p[0], env);
	if (lvl > 0)
	{
		depth((t_pos[3]){p[0], mid(p[0], p[1]), mid(p[0], p[2])}, env, lvl - 1);
		depth((t_pos[3]){p[1], mid(p[0], p[1]), mid(p[1], p[2])}, env, lvl - 1);
		depth((t_pos[3]){p[2], mid(p[0], p[2]), mid(p[1], p[2])}, env, lvl - 1);
	}
}

void			sierpinski(t_env *env)
{
	t_pos p[3];

	p[0].x = 50 * env->cam->zoom - env->cam->offset_y;
	p[0].y = 700 * env->cam->zoom - env->cam->offset_x;
	p[1].x = 750 * env->cam->zoom - env->cam->offset_y;
	p[1].y = 700 * env->cam->zoom - env->cam->offset_x;
	p[2].x = p[0].x + (p[1].x - p[0].x) / 2;
	p[2].y = p[0].y - sqrt(pow2(p[1].x - p[0].x) - pow2((p[1].x - p[0].x) / 2));
	depth(p, env, env->checks);
	hud_background(env);
}
