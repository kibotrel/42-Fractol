/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 08:27:55 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/22 01:24:52 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"

int	valid_fractal(char *name)
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
	if (!ft_strcmp(ft_strlowcase(name), "koch"))
		return (KOCH);
	return (-1);
}
