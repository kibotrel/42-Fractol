/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:01:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/07/11 17:08:13 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "env.h"
#include "fractol.h"

void		hud_background(t_env *env)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= HEIGHT)
	{
		x = 799;
		while (++x <= WIDTH)
		{
			if (y < 50 || (y >= 400 && y < 450))
				pixel_to_image(env, x, y, DARK_GRAY);
			else
				pixel_to_image(env, x, y, LIGHT_GRAY);
		}
	}
}

static void	region_bounds(t_env *env, t_posd *l, t_posd *b)
{
	l->x = env->x_min + (float)env->cam->offset_y;
	l->y = env->y_min + (float)env->cam->offset_x;
	b->x = env->x_max + (float)env->cam->offset_y;
	b->y = env->y_max + (float)env->cam->offset_x;
}

static void	fill_fields(t_infos *i, t_env *env)
{
	t_posd	l;
	t_posd	b;

	region_bounds(env, &l, &b);
	if (env->fractal == SIERPINSKI
		|| env->fractal == KOCH
		|| env->fractal == FLOWER)
		sprintf(i->checks, "Depth level   : %d", env->checks);
	else if (env->fractal == BARNSLEY)
		sprintf(i->checks, "Population    : %d", env->checks);
	else
		sprintf(i->checks, "Iterations    : %d", env->checks);
	if (env->zoom_count < ZOOM_MAX)
		sprintf(i->zoom, "Zoom          : x%.2f", env->cam->zoom);
	sprintf(i->c, "%+.5f %+.5fi", env->julia_x, env->julia_y);
	sprintf(i->off_x, "Offset X      : %.2f", env->cam->offset_y);
	sprintf(i->off_y, "Offset Y      : %.2f", env->cam->offset_x);
	if (env->fractal != SIERPINSKI
		&& env->fractal != KOCH
		&& env->fractal != FLOWER)
		sprintf(i->region, "%+.5f %+.5fi to %+.5f %+.5fi", l.x, l.y, b.x, b.y);
	if (env->fractal < SIERPINSKI)
		sprintf(i->sound, "Sound name    : %s\n", env->sound_name);
}

static void	fractal_infos(void *id, void *win, t_env *env)
{
	t_infos i;

	fill_fields(&i, env);
	get_fractal_name(env->mlx->id, env->mlx->win, env);
	mlx_string_put(id, win, 1040, 15, WHITE, "Informations");
	mlx_string_put(id, win, 955, 100, WHITE, i.checks);
	infos_zoom(env, env->mlx->id, env->mlx->win, i);
	mlx_string_put(id, win, 955, 140, WHITE, i.off_x);
	mlx_string_put(id, win, 955, 160, WHITE, i.off_y);
	infos_color(env, env->mlx->id, env->mlx->win);
	if (env->fractal != SIERPINSKI
		&& env->fractal != KOCH
		&& env->fractal != BARNSLEY
		&& env->fractal != FLOWER)
		mlx_string_put(id, win, 955, 220, WHITE, i.sound);
	infos_complex(env, env->mlx->id, env->mlx->win, i);
}

void		hud_infos(t_env *env)
{
	fractal_infos(env->mlx->id, env->mlx->win, env);
	fractal_controls(env->mlx->id, env->mlx->win);
}
