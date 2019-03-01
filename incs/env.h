/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:14:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/01 21:22:13 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Minilibx informations
*/

# define WIDTH		1200
# define TITLE		"[Minilibx Project] Fractol 42"
# define HEIGHT		1200

/*
**	Available fractals
*/

# define MANDELBROT	1

/*
**	Used keycodes to communicate with mlx
*/

# define A			0
# define S			1
# define D			2
# define W			13
# define M			46
# define ESC		53
# define PG_UP		116
# define PG_DOWN	121
/*
**	Useful Macros
*/

# define LIM		128
# define OFFSET		0.0625

/*
**	Color codes
*/

# define BLUE		0x000033
# define WHITE		0xFFFFFF
# define BLACK		0x000000

/*
**	Error messages
*/

# define ERR_NAME	"\033[31;1mError:\033[0m Fractal unavailable."
# define ERR_MALLOC	"\033[31;1mError :\033[0m Can't allocate memory."

#endif
