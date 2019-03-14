/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:30:56 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/14 06:46:36 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "env.h"
#include "fractol.h"

#include <stdio.h>//
#include <math.h>//

void	offset(t_env *env, int key)
{
	new_img(env);
	if (key == W)
		env->cam->offset_x += OFFSET / env->cam->zoom;
	if (key == A)
		env->cam->offset_y += OFFSET / env->cam->zoom;
	if (key == S)
		env->cam->offset_x -= OFFSET / env->cam->zoom;
	if (key == D)
		env->cam->offset_y -= OFFSET / env->cam->zoom;
	draw_fractal(env);
}

void	details(t_env *env, int key)
{
	new_img(env);
	if (key == PG_UP)
		env->checks += 10;
	if (key == PG_DOWN && env->checks >= 20)
		env->checks -= 10;
	draw_fractal(env);
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
		draw_fractal(env);
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
	env->checks = 50;
	env->cam->offset_y = 0.0;
	env->cam->offset_x = 0.0;
	env->y_max = 2;
	env->y_min = -2;
	env->x_max = 2;
	env->x_min = -2;
	env->zoom_count = 1;
	env->cam->zoom = 1;
	if (env->cam->shift == NEON)
		set1(env);
	else if (env->cam->shift == RED_ORANGE)
		set2(env);
	else if (env->cam->shift == FACEBOOK)
		set3(env);
	else
		color_preset(env);
	draw_fractal(env);
}

void	zoom(int direction, int x, int y, t_env *env)
{
	if (y >= 0 && y <= HEIGHT && x >= 0 && x <= WIDTH)
	{
		new_img(env);
		if (direction == ZOOM_IN)
		{
			env->zoom_count++;
			env->cam->zoom *= 1.1;
		}
		else if (direction == ZOOM_OUT && env->zoom_count > 1)
		{
			env->zoom_count--;
			env->cam->zoom /= 1.1;
		}
		env->y_min = -2 + (4 / 2) - (4 / 2 / env->cam->zoom);
		env->y_max = env->y_min + (4 / env->cam->zoom);
		env->x_min = -2 + (4 / 2) - (4 /  2 / env->cam->zoom);
		env->x_max = env->x_min + (4 /env->cam->zoom);
		draw_fractal(env);
	}
}
