/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:33:09 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 17:27:28 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fractol.h"

void	free_all(t_env *env, int state)
{
	if (state >= 1)
	{
		if (state >= 3)
		{
			mlx_destroy_image(env->mlx->id, env->mlx->img->data);
			free(env->mlx->img);
		}
		if (state >= 2)
		{
			mlx_destroy_window(env->mlx->id, env->mlx->win);
			free(env->mlx);
		}
		if (state >= 4)
			free(env->cam);
		free(env);
	}
}
