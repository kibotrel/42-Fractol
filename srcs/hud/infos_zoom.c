/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:28:53 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 14:57:47 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "env.h"
#include "fractol.h"

void	infos_zoom(t_env *env, void *id, void *win, t_infos i)
{
	if (ft_strlen(i.zoom) < LEN_ZOOM_MAX && env->zoom_count < ZOOM_MAX)
		mlx_string_put(id, win, 955, 120, WHITE, i.zoom);
	else
	{
		mlx_string_put(id, win, 955, 120, WHITE, "Zoom          :");
		mlx_string_put(id, win, 1115, 120, TRUE_RED, "Too big to fit in !");
	}
}
