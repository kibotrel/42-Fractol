/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:28:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/16 06:09:37 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "mlx.h"
#include "env.h"
#include "fractol.h"

static void	init_mlx(t_env *env)
{
	t_mlx	*tmp;

	if (!(tmp = (t_mlx*)malloc(sizeof(t_mlx))))
		ft_print_error(ERR_MALLOC, 2);
	tmp->id = mlx_init();
	tmp->win = mlx_new_window(tmp->id, WIDTH, HEIGHT, TITLE);
	env->mlx = tmp;
}

static void	init_img(t_env *env)
{
	t_img	*tmp;

	if (!(tmp = (t_img*)malloc(sizeof(t_img))))
		ft_print_error(ERR_MALLOC, 2);
	tmp->id = mlx_new_image(env->mlx->id, WIDTH, HEIGHT);
	tmp->data = mlx_get_data_addr(tmp->id, &tmp->bpp, &tmp->size, &tmp->endian);
	env->mlx->img = tmp;
}

static void	init_cam(t_env *env)
{
	t_cam	*tmp;

	if (!(tmp = (t_cam*)malloc(sizeof(t_cam))))
		ft_print_error(ERR_MALLOC, 2);
	tmp->zoom = 1;
	tmp->offset_y = 0.0;
	tmp->offset_x = 0.0;
	tmp->color = GRADIENT;
	tmp->shift = DEFAULT;
	env->cam = tmp;
}

static void	init_env(t_env *env, int fractal)
{
	env->fractal = fractal;
	env->checks = 25;
	env->base_color = BLACK;
	env->julia_x = 0.0;
	env->julia_y = 0.0;
	env->child = 0;
	env->toggle_julia = -1;
	env->sound_name = "sound.wav";
	env->y_max = 2;
	env->y_min = -2;
	env->x_max = 2;
	env->x_min = -2;
	env->zoom_count = 1;
	color_preset(env);
}

t_env		*initialize(int fractal)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_print_error(ERR_MALLOC, 2);
	init_mlx(env);
	init_img(env);
	init_cam(env);
	init_env(env, fractal);
	return (env);
}
