/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:14:17 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/22 01:29:43 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fractol.h"

void	infos_complex(t_env *env, void *id, void *win, t_infos i)
{
	if (env->fractal != SIERPINSKI && env->fractal != KOCH)
	{
		mlx_string_put(id, win, 1025, 260, WHITE, "Explored region");
		mlx_string_put(id, win, 900, 280, WHITE, i.region);
		if (env->fractal == JULIA || env->fractal == BURNING_JULIA)
		{
			mlx_string_put(id, win, 1030, 320, WHITE, "Preset complex");
			mlx_string_put(id, win, 1010, 340, WHITE, i.c);
		}
	}
}
