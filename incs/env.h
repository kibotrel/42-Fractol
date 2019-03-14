/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:14:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/14 05:26:40 by kibotrel         ###   ########.fr       */
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

# define JULIA			1
# define MANDELBROT		0
# define BURNING_SHIP	2

/*
**	Used keycodes to communicate with mlx
*/

# define A				0
# define S				1
# define D				2
# define H				4
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
# define PLUS			24
# define MINUS			27
# define TILDE			50
# define PG_UP			116
# define PG_DOWN		121
# define SCROLL_UP		4
# define SCROLL_DOWN	5

/*
**	Useful Macros
*/

# define LIM			8
# define MAX			100
# define AREA			-1
# define NEON			1
# define SCALE			400
# define OFFSET			0.0625
# define DEFAULT		0
# define ZOOM_IN		1
# define GRADIENT		1
# define ZOOM_MIN		1
# define ZOOM_OUT		2
# define FACEBOOK		3
# define ZOOM_MAX		100
# define RED_ORANGE		2
# define ZOOM_COEFF		1.15

/*
**	Color codes
*/

# define RED			0x610000
# define BLUE			0x000033
# define WHITE			0xFFFFFF
# define BROWN			0x180002
# define BLACK			0x000000
# define ORANGE			0xE6C832
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

# define JULIABROT_0	0x19071A
# define JULIABROT_1	0x09012F
# define JULIABROT_2	0x040449
# define JULIABROT_3	0x000764
# define JULIABROT_4	0x0C2C8A
# define JULIABROT_5	0x1852B1
# define JULIABROT_6	0x397DD1
# define JULIABROT_7	0x86B5E5
# define JULIABROT_8	0xD3ECF8
# define JULIABROT_9	0xF1E9BF
# define JULIABROT_10	0xF8C95F
# define JULIABROT_11	0xFFAA00
# define JULIABROT_12	0xCC8000
# define JULIABROT_13	0x995700
# define JULIABROT_14	0x6A3403
# define JULIABROT_15	0x421E0F

/*
**	Error messages
*/

# define ERR_NAME		"\033[31;1mError:\033[0m Fractal unavailable."
# define ERR_MALLOC		"\033[31;1mError :\033[0m Can't allocate memory."

#endif
