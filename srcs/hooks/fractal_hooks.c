/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:31:03 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/29 19:42:36 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	fractal_key_press(int key, t_env *env)
{
	if (key == M && env->fractal < SIERPINSKI)
		color_mode(env);
	else if (key == PG_UP || key == PG_DOWN)
		details(env, key);
	else if (key == W || key == A || key == S || key == D)
		offset(env, key);
	else if ((key == Z || key == X || key == C) && env->cam->color == AREA)
		colorset(env, key);
	else if ((key == V || key == B || key == N) && env->cam->color == GRADIENT)
		base_color(env, key);
	else if ((key == P && env->cam->color == AREA))
		psycho_effect(env);
	else if (key == R)
		reset(env);
	else if (key == TILDE)
		env->toggle_julia *= -1;
	else if (key == J || key == K || key == L)
		change_sound(env, key);
	else if (key >= NUM_1 && key <= NUM_8)
		change_fractal(env, key);
	else if (key == PLUS || key == MINUS)
		keyboard_zoom(env, key);
}

void	fractal_mouse_move(int x, int y, t_env *env)
{
	if ((env->fractal == JULIA || env->fractal == BURNING_JULIA)
		&& env->toggle_julia == 1)
	{
		if (x >= 0 && x < 400 && y >= 0 && y <= 800)
			env->julia_x = map(x, fill_data(0, 399, -1, 0));
		else if (x >= 400 && x <= 800 && y >= 0 && y <= 800)
			env->julia_x = map(x, fill_data(400, 800, 0, 1));
		if (y >= 0 && y < 400 && x >= 0 && x <= 800)
			env->julia_y = map(y, fill_data(0, 399, -1, 0));
		else if (y >= 400 && y <= 800 && x >= 0 && x <= 800)
			env->julia_y = map(y, fill_data(400, 800, 0, 1));
		threads(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
}

void	fractal_mouse_press(int button, int x, int y, t_env *env)
{
	if (button == SCROLL_UP && env->fractal < SIERPINSKI)
		zoom_mouse(ZOOM_IN, x, y, env);
	else if (button == SCROLL_DOWN && env->fractal < SIERPINSKI)
		zoom_mouse(ZOOM_OUT, x, y, env);
}
