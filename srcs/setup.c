/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:28:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/22 18:39:46 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //

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
	tmp->offset_y = 0;
	tmp->offset_x = 0;
	env->cam = tmp;
}

static void	init_env(t_env *env, int fractal)
{
	env->fractal = fractal;
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

	// printf("\nMlx:\n\tid  : %p\n\twin : %p\n\n", env->mlx->id, env->mlx->win);
	// printf("Image:\n\tid     : %p\n\tbpp    : %d\n\tsize   : %d\n\tendian : %d\n\n", env->mlx->img->id, env->mlx->img->bpp, env->mlx->img->size, env->mlx->img->endian);
	// printf("Cam:\n\thud      : %d\n\tzoom     : %d\n\toffset_y : %d\n\toffset_x : %d\n\n", env->cam->hud, env->cam->zoom, env->cam->offset_y, env->cam->offset_x);
	// printf("Env:\n\tfractal : %d\n\n", env->fractal);

	return (env);
}
