/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:52:30 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/20 19:28:46 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_usage(void)
{
	ft_putendl("\n\033[32;1musage: ./fractol fractal_name\033[0;36m");
	ft_putendl("\n\tAvailable fractals:\n\n\t- \033[0;31;1mNOT HANDLED YET\033[0;36m");
	ft_putendl("\n\033[0m\033[32;1mError handling:\033[0;36m");
	ft_putendl("\n\tEach following error code are handled by the program");
	ft_putendl("\n\t- Failed memory allocation (1) \033[0;31;1mNOT HANDLED YET\033[0;36m\n\t- Invalid fractal (2) \033[0;31;1mNOT HANDLED YET\033[0;36m");
	ft_putendl("\n\tUse \"echo $?\" to know the last process returned value");
	ft_putendl("\n\033[0m\033[32;1mControls:\033[0;36m");
	ft_putendl("\n\tThe following inputs are handled in the mlx window");
	ft_putendl("\n\t- Move the map along x and y axis (W,A,S,D) \033[0;31;1mNOT HANDLED YET\033[0;36m");
	ft_putendl("\t- Change colorset (Z,X,C) \033[0;31;1mNOT HANDLED YET\033[0;36m\n\t- Reset view point (R) \033[0;31;1mNOT HANDLED YET\033[0;36m");
	ft_putendl("\t- Toggle HUD (H) \033[0;31;1mNOT HANDLED YET\033[0;36m");
	ft_putendl("\t- Close the window and exit the program (ESC) \033[0;31;1mNOT HANDLED YET\033[0;36m");
	ft_putendl("\n\t\t\t\t\t\t\033[0m\033[32;1mMade by kibotrel\n\033[0m");
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_putendl(av[1]);
	}
	else
		print_usage();

	return (0);
}
