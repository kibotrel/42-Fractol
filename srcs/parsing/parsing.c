/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 08:27:55 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/29 16:42:42 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"

int	valid_fractal(char *name)
{
	if (!ft_strcmp(ft_strlowcase(name), "mandelbrot"))
		return (MANDELBROT);
	else if (!ft_strcmp(ft_strlowcase(name), "julia"))
		return (JULIA);
	else if (!ft_strcmp(ft_strlowcase(name), "burning ship"))
		return (BURNING_SHIP);
	else if (!ft_strcmp(ft_strlowcase(name), "burning julia"))
		return (BURNING_JULIA);
	else if (!ft_strcmp(ft_strlowcase(name), "sierpinski"))
		return (SIERPINSKI);
	else if (!ft_strcmp(ft_strlowcase(name), "koch"))
		return (KOCH);
	else if (!ft_strcmp(ft_strlowcase(name), "barnsley"))
		return (BARNSLEY);
	else if (!ft_strcmp(ft_strlowcase(name), "flower"))
		return (FLOWER);
	return (-1);
}
