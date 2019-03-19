/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 02:13:46 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 15:22:06 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "env.h"
#include "fractol.h"

t_pos	middle(t_pos a, t_pos b)
{
	t_pos mid;

	mid.x = a.x + (b.x - a.x) / 2;
	mid.y = a.y + (b.y - a.y) / 2;
	return (mid);
}

void	recursion(t_pos a, t_pos b, t_pos c, t_env *env, int level)
{
	draw_line(a, b, env);
	draw_line(b, c, env);
	draw_line(c, a, env);
	if (level > 0)
	{
		recursion(a, middle(a, b), middle(a, c), env, level - 1);
		recursion(b, middle(a, b), middle(b, c), env, level - 1);
		recursion(c, middle(a, c), middle(b, c), env, level - 1);
	}
}

void	sierpinski(t_env *env)
{
	t_pos	a;
	t_pos	b;
	t_pos	c;

	a.x = 50 * env->cam->zoom - env->cam->offset_y;
	a.y = 700 * env->cam->zoom - env->cam->offset_x;
	b.x = 750 * env->cam->zoom - env->cam->offset_y;
	b.y = 700 * env->cam->zoom - env->cam->offset_x;
	c.x = a.x + (b.x - a.x) / 2;
	c.y = a.y - sqrt(pow(b.x - a.x, 2) - pow((b.x - a.x) / 2, 2));
	recursion(a, b, c, env, env->checks);
}
