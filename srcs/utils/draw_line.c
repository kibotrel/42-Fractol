/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:38:12 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 11:56:08 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "fractol.h"

static t_line	setup_params(t_pos a, t_pos b)
{
	t_line	params;

	params.sign_y = (a.y < b.y ? 1 : -1);
	params.sign_x = (a.x < b.x ? 1 : -1);
	params.delta_y = abs(b.y - a.y);
	params.delta_x = abs(b.x - a.x);
	params.offset = params.delta_x - params.delta_y;
	params.error = 0;
	return (params);
}

void			draw_line(t_pos a, t_pos b, t_env *env)
{
	t_line	params;
	t_pos	p;

	params = setup_params(a, b);
	p = a;
	while (p.y != b.y || p.x != b.x)
	{
		pixel_to_image(env, p.x, p.y, WHITE);
		if ((params.error = params.offset * 2) > -params.delta_y)
		{
			params.offset -= params.delta_y;
			p.x += params.sign_x;
		}
		if (params.error < params.delta_x)
		{
			params.offset += params.delta_x;
			p.y += params.sign_y;
		}
	}
	pixel_to_image(env, p.x, p.y, WHITE);
}
