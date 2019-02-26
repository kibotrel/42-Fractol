/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:14:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 19:09:29 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Minilibx informations
*/

# define WIDTH 1200
# define TITLE "[Minilibx Project] Fractol 42"
# define HEIGHT 1200

/*
**	Available fractals
*/

# define MANDELBROT 1

/*
**	Used keycodes to communicate with mlx
*/

# define ESC 53

/*
**	Color codes
*/

# define RED 0xFF0000
# define BLUE 0x000033
# define BLACK 0x000000
# define GREEN 0x00FF00
# define WHITE	0xFFFFFF
# define YELLOW 0xFFFF000
# define PURPLE 0xFF00FF
# define SMOKY_TOPAZ 0xA63D40
# define MIDDLE_YELLOW 0xE9B872

/*
**	Error messages
*/

# define ERR_NAME "\033[31;1mError:\033[0m Fractal unavailable."
# define ERR_MALLOC "\033[31;1mError :\033[0m Can't allocate memory."

#endif
