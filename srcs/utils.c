/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:33:09 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 17:08:24 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "fractol.h"

void	free_all(t_env *env)
{
	free(env->mlx->img);
	free(env->mlx);
	free(env->cam);
	free(env);
}

t_map	fill_data(double start, double end, double min, double max)
{
	t_map	tmp;

	tmp.in_s = start;
	tmp.in_e = end;
	tmp.out_s = min;
	tmp.out_e = max;
	return (tmp);
}

double	map(double n, t_map m)
{
	return ((n - m.in_s) / (m.in_e - m.in_s) * (m.out_e - m.out_s) + m.out_s);
}
