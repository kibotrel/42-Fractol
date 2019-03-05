/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:14:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/05 08:04:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Minilibx informations
*/

# define WIDTH			800
# define TITLE			"[Minilibx Project] Fractol 42"
# define HEIGHT			800

/*
**	Available fractals
*/

# define MANDELBROT		0
# define JULIA			1

/*
**	Used keycodes to communicate with mlx
*/

# define A				0
# define S				1
# define D				2
# define Z				6
# define X				7
# define C				8
# define V				9
# define B				11
# define W				13
# define R				15
# define P				35
# define N				45
# define M				46
# define ESC			53
# define PG_UP			116
# define PG_DOWN		121

/*
**	Useful Macros
*/

# define LIM			8
# define NEON			1
# define AREA			-1
# define OFFSET			0.0625
# define DEFAULT		0
# define GRADIENT		1
# define FACEBOOK		3
# define RED_ORANGE		2

/*
**	Color codes
*/

# define RED			0x610000
# define BLUE			0x000033
# define WHITE			0xFFFFFF
# define BLACK			0x000000
# define YELLOW			0xFFFF00

# define NEON_0			0xFE0000
# define NEON_1			0xFDFE02
# define NEON_2			0x0BFF01
# define NEON_3			0x011EFE
# define NEON_4			0xFE00F6

# define FACEBOOK_0		0x3B5998
# define FACEBOOK_1		0x8B9DC3
# define FACEBOOK_2		0xDFE3EE
# define FACEBOOK_3		0xF7F7F7
# define FACEBOOK_4		0xFFFFFF

# define RED_ORANGE_0	0xFF0000
# define RED_ORANGE_1	0xFF4D00
# define RED_ORANGE_2	0xFF7400
# define RED_ORANGE_3	0xFF9A00
# define RED_ORANGE_4	0xFFC100

# define MANDELBROT_0	0x19071A
# define MANDELBROT_1	0x09012F
# define MANDELBROT_2	0x040449
# define MANDELBROT_3	0x000764
# define MANDELBROT_4	0x0C2C8A
# define MANDELBROT_5	0x1852B1
# define MANDELBROT_6	0x397DD1
# define MANDELBROT_7	0x86B5E5
# define MANDELBROT_8	0xD3ECF8
# define MANDELBROT_9	0xF1E9BF
# define MANDELBROT_10	0xF8C95F
# define MANDELBROT_11	0xFFAA00
# define MANDELBROT_12	0xCC8000
# define MANDELBROT_13	0x995700
# define MANDELBROT_14	0x6A3403
# define MANDELBROT_15	0x421E0F

/*
**	Error messages
*/

# define ERR_NAME		"\033[31;1mError:\033[0m Fractal unavailable."
# define ERR_MALLOC		"\033[31;1mError :\033[0m Can't allocate memory."

#endif
