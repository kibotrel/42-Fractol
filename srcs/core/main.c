/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:52:30 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 19:00:29 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "env.h"
#include "fractol.h"

int	main(int ac, char **av)
{
	t_env	*env;
	int		fractal;

	if (ac == 2)
	{
		if ((fractal = valid_fractal(av[1])) == -1)
		{
			fractal_list();
			ft_print_error(ERR_NAME, 1);
		}
		else
		{
			env = initialize(fractal);
			if (env->fractal != MENU)
				fractal_to_window(env);
			else
				menu(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
			hooks(env);
			mlx_loop(env->mlx->id);
		}
	}
	else
		return (0 * usage());
}
