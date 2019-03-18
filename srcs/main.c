/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:52:30 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 07:44:48 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "env.h"
#include "fractol.h"

static void	print_usage(void)
{
	ft_putendl("\n\033[32;1musage: ./fractol fractal_name\033[0;36m");
	ft_putendl("\n\tAvailable fractals:\n\n\t- Mandelbrot\n\t- Julia");
	ft_putendl("\t- Burning Ship\n\t- Burning Julia\n\t- Sierpinski");
	ft_putendl("\n\tUse \"./fractol menu\" to display the main menu window \033[0;31;1mNOT HANDLED YET\033[0;36m");
	ft_putendl("\n\033[0m\033[32;1mError handling:\033[0;36m");
	ft_putendl("\n\tEach following error code are handled by the program");
	ft_putendl("\n\t- Invalid fractal (1)\n\t- Failed memory allocation (2)");
	ft_putendl("\n\tUse \"echo $?\" to know the last process returned value");
	ft_putendl("\n\033[0m\033[32;1mKeyboard controls:\033[0;36m");
	ft_putendl("\n\tThe following inputs are handled in the mlx window");
	ft_putendl("\n\t- Move the map along x and y axis (W,A,S,D)");
	ft_putendl("\t- Area colorset (Z,X,C)\n\t- Gradient colorset (V,B,N)");
	ft_putendl("\t- Color mode switch between gradient and areas (M)");
	ft_putendl("\t- Reset view point (R)\n\t- Configurate Julia (Tilde)");
	ft_putendl("\t- Close the window and exit the program (ESC)");
	ft_putendl("\t- Psychedelic mode (P)\n\t- Change Sound (J,K,L)");
	ft_putendl("\t- Select fractal (1,2,3)");
	ft_putendl("\t- Change details amount (Page_Up,Page_Down)");
	ft_putendl("\n\033[0m\033[32;1mMouse controls:\033[0;36m");
	ft_putendl("\n\tThe following inputs are handled in the mlx window");
	ft_putendl("\n\t- Zoom (Scroll)");
	ft_putendl("\t- Julia set parameters (Cursor position)");
	ft_putendl("\n\t\t\t\t\t\t\033[0m\033[32;1mMade by kibotrel\n\033[0m");
}

static int	valid_fractal(char *name)
{
	if (!ft_strcmp(ft_strlowcase(name), "mandelbrot"))
		return (MANDELBROT);
	if (!ft_strcmp(ft_strlowcase(name), "julia"))
		return (JULIA);
	if (!ft_strcmp(ft_strlowcase(name), "burning ship"))
		return (BURNING_SHIP);
	if (!ft_strcmp(ft_strlowcase(name), "burning julia"))
		return (BURNING_JULIA);
	if (!ft_strcmp(ft_strlowcase(name), "sierpinski"))
		return (SIERPINSKI);
	return (-1);
}

int			main(int ac, char **av)
{
	t_env	*env;
	int		fractal;

	if (ac == 2)
	{
		if ((fractal = valid_fractal(av[1])) == -1)
			ft_print_error(ERR_NAME, 1);
		else
		{
			env = initialize(fractal);
			draw_fractal(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
			hooks(env);
			mlx_loop(env->mlx->id);
		}
	}
	else
		print_usage();
	return (0);
}
