/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:28:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:29 by kibotrel         ###   ########.fr       */
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
	tmp->hud = 1;
	tmp->zoom = 1;
	tmp->offset_y = 0.0;
	tmp->offset_x = 0.0;
	tmp->color = 1;
	env->cam = tmp;
}

static void	init_env(t_env *env, int fractal)
{
	env->fractal = fractal;
	env->checks = 50;
	env->palette[0] = 0x421E0F;
	env->palette[1] = 0x19071A;
	env->palette[2] = 0x09012F;
	env->palette[3] = 0x040449;
	env->palette[4] = 0x000764;
	env->palette[5] = 0x0C2C8A;
	env->palette[6] = 0x1852B1;
	env->palette[7] = 0x397DD1;
	env->palette[8] = 0x86B5E5;
	env->palette[9] = 0xD3ECF8;
	env->palette[10] = 0xF1E9BF;
	env->palette[11] = 0xF8C95F;
	env->palette[12] = 0xFFAA00;
	env->palette[13] = 0xCC8000;
	env->palette[14] = 0x995700;
	env->palette[15] = 0x6A3403;
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
