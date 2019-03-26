/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:30:44 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/26 12:54:20 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

void	new_img(t_env *env)
{
	mlx_destroy_image(env->mlx->id, env->mlx->img->id);
	env->mlx->img->id = mlx_new_image(env->mlx->id, WIDTH, HEIGHT);
	env->mlx->img->data = mlx_get_data_addr(env->mlx->img->id,
		&(env->mlx->img->bpp), &(env->mlx->img->size),
		&(env->mlx->img->endian));
}

void	pixel_to_image(t_env *env, int x, int y, int color)
{
	int	i;

	i = (x * env->mlx->img->bpp / 8) + (y * env->mlx->img->size);
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		env->mlx->img->data[i] = color;
		env->mlx->img->data[++i] = color >> 8;
		env->mlx->img->data[++i] = color >> 16;
	}
}
