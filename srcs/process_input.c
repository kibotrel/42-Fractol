/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:30:56 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 06:49:53 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "env.h"
#include "fractol.h"

void	offset(t_env *env, int key)
{
	new_img(env);
	if (key == W && env->fractal == SIERPINSKI)
		env->cam->offset_x += 25;
	else if (key == A && env->fractal == SIERPINSKI)
		env->cam->offset_y += 25;
	else if (key == S && env->fractal == SIERPINSKI)
		env->cam->offset_x -= 25;
	else if (key == D && env->fractal == SIERPINSKI)
		env->cam->offset_y -= 25;
	else if (key == W && env->cam->offset_x < OFFSET_MAX)
		env->cam->offset_x += OFFSET / env->cam->zoom;
	else if (key == A && env->cam->offset_y < OFFSET_MAX)
		env->cam->offset_y += OFFSET / env->cam->zoom;
	else if (key == S && env->cam->offset_x > OFFSET_MIN)
		env->cam->offset_x -= OFFSET / env->cam->zoom;
	else if (key == D && env->cam->offset_y > OFFSET_MIN)
		env->cam->offset_y -= OFFSET / env->cam->zoom;
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}

void	details(t_env *env, int key)
{
	new_img(env);
	if (key == PG_UP && env->fractal != SIERPINSKI && env->checks <= MAX_LOOPS)
		env->checks += 5;
	else if (key == PG_DOWN && env->fractal != SIERPINSKI && env->checks >= 20)
		env->checks -= 5;
	else if (key == PG_UP && env->fractal == SIERPINSKI && env->checks < 14)
		env->checks++;
	else if (key == PG_DOWN && env->fractal == SIERPINSKI && env->checks >= 1)
		env->checks--;
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}

void	psycho_effect(t_env *env)
{
	char	*command;

	if (!env->child)
		env->child = fork();
	if (env->child > 0)
	{
		new_img(env);
		if (!env->cam->shift)
			shift_default(env);
		else
			shift_color(env);
		draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
	else if (env->child == 0)
		while (1)
		{
			command = ft_strjoin("afplay -q 1 ", env->sound_name);
			system(command);
			free(command);
		}
}

void	reset(t_env *env)
{
	new_img(env);
	set_checks(env);
	env->cam->offset_y = 0.0;
	env->cam->offset_x = 0.0;
	env->y_max = 2;
	env->y_min = -2;
	env->x_max = 2;
	env->x_min = -2;
	env->zoom_count = 1;
	env->cam->zoom = 1;
	env->julia_x = 0;
	env->julia_y = 0;
	if (env->cam->shift == PASTEL)
		set1(env);
	else if (env->cam->shift == RED_ORANGE)
		set2(env);
	else if (env->cam->shift == FOREST)
		set3(env);
	else
		color_preset(env);
	draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
}

#include <stdio.h>

void	zoom_mouse(int direction, double x, double y, t_env *env)
{
	if (y >= 0 && y <= 800 && x >= 0 && x <= 800)
	{
		new_img(env);
		if (direction == ZOOM_IN)
		{
			env->zoom_count ++;
			if (x > 0 && x < 400)
				env->cam->offset_y -= (OFFSET / env->cam->zoom) * ((400 - x) / 64);
			else if (x >= 400 && x < 800)
				env->cam->offset_y += (OFFSET / env->cam->zoom) * ((x - 400) / 64);
			if (y > 0 && y < 400)
				env->cam->offset_x -= (OFFSET / env->cam->zoom) * ((400 - y) / 64);
			else if (y >= 400 && y < 800)
				env->cam->offset_x += (OFFSET / env->cam->zoom) * ((y - 400) / 64);
			env->cam->zoom *= 1.1;
		}
		else if (direction == ZOOM_OUT && env->zoom_count > 1)
		{
			env->zoom_count--;
			if ((env->cam->zoom /= 1.1) < 1)
				env->cam->zoom = 1;
		}
		update_bounds(env);
		draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
}
