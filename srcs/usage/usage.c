/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 07:58:06 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/26 16:16:52 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		fractal_list(void)
{
	ft_putendl("\n\033[32;1musage: ./fractol fractal_name\033[0;36m");
	ft_putendl("\n\tAvailable fractals:");
	ft_putendl("\n\t- Mandelbrot\n\t- Julia\n\t- Burning Ship");
	ft_putendl("\t- Burning Julia\n\t- Sierpinski\n\t- Koch\n\t- Barnsley");
	ft_putendl("\n\tUse \"./fractol menu\" to display the main menu window \033[0;31;1mNOT HANDLED YET\033[0;36m\n");
}

static void	error_handling(void)
{
	ft_putendl("\033[0m\033[32;1mError handling:\033[0;36m");
	ft_putendl("\n\tEach following error code are handled by the program");
	ft_putendl("\n\t- Invalid fractal (1)\n\t- Failed memory allocation (2)");
	ft_putendl("\t- Failed to fork the process (3)");
	ft_putendl("\n\tUse \"echo $?\" to know the last process returned value");
}

static void	keyboard_controls(void)
{
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
}

static void	mouse_controls(void)
{
	ft_putendl("\n\033[0m\033[32;1mMouse controls:\033[0;36m");
	ft_putendl("\n\tThe following inputs are handled in the mlx window");
	ft_putendl("\n\t- Zoom (Scroll)");
	ft_putendl("\t- Julia set parameters (Cursor position)");
	ft_putendl("\n\t\t\t\t\t\t\033[0m\033[32;1mMade by kibotrel\n\033[0m");
}

void		usage(void)
{
	fractal_list();
	error_handling();
	keyboard_controls();
	mouse_controls();
}
