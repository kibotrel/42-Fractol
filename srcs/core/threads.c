/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 01:06:30 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/28 06:52:18 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "env.h"
#include "fractol.h"

static void	selector(t_env *env)
{
	pthread_t	s;
	int			i;
	static void	(*fractal[5])(t_env*, int thread) =
	{mandelbrot, julia, burning_ship, burning_julia};

	i = 0;
	s = pthread_self();
	while (s != env->threads[i])
		i++;
	fractal[env->fractal](env, i);
	pthread_exit(NULL);
}
void	threads(t_env *env, void *id, void *win, void *img)
{
	int	i;

	i = -1;
	if (env->fractal >= SIERPINSKI)
	{
		draw_fractal(env);
		mlx_put_image_to_window(id, win, img, 0, 0);
		hud_infos(env);
	}
	else
	{
		while (++i < THREADS)
			pthread_create(&env->threads[i], NULL, (void*)selector, env);
		i = -1;
		while (++i < THREADS)
			pthread_join(env->threads[i], NULL);
 		mlx_put_image_to_window(id, win, img, 0, 0);
		hud_infos(env);
	}
}
