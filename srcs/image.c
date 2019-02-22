/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:30:44 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/22 18:32:28 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fractol.h"

void	pixel_to_image(t_env *env, int x, int y, int color)
{
	int		i;

	i = (x * env->mlx->img->bpp / 8) + (y * env->mlx->img->size);
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		env->mlx->img->data[i] = color;
		env->mlx->img->data[++i] = color >> 8;
		env->mlx->img->data[++i] = color >> 16;
	}
}
