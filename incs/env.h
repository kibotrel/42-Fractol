/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:14:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/21 23:11:33 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Minilibx informations
*/

# define WIDTH			1400
# define TITLE			"[Minilibx Project] Fractol 42"
# define HEIGHT			800

/*
**	Available fractals
*/

# define JULIA			1
# define MANDELBROT		0
# define SIERPINSKI		4
# define BURNING_SHIP	2
# define BURNING_JULIA	3

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
# define L				37
# define J				38
# define K				40
# define N				45
# define M				46
# define ESC			53
# define PLUS			24
# define NUM_1			83
# define NUM_2			84
# define NUM_3			85
# define NUM_4			86
# define NUM_5			87
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
# define SCALE			400
# define OFFSET			0.0625
# define PASTEL			1
# define DEFAULT		0
# define ZOOM_IN		1
# define GRADIENT		1
# define ZOOM_MIN		1
# define ZOOM_OUT		2
# define FOREST			3
# define ZOOM_MAX		650
# define RED_ORANGE		2
# define MAX_LOOPS		9999995
# define OFFSET_MIN		-2.75
# define ZOOM_COEFF		1.15
# define OFFSET_MAX		2.75
# define LEN_ZOOM_MAX	44

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
# define TRUE_RED		0xFF0000

# define PASTEL_0		0xF05F66
# define PASTEL_1		0xFF7A79
# define PASTEL_2		0xFFB152
# define PASTEL_3		0xFFB152
# define PASTEL_4		0xFFF18E

# define FOREST_0		0x3D332C
# define FOREST_1		0x4E4B37
# define FOREST_2		0x447733
# define FOREST_3		0x52A84D
# define FOREST_4		0x6FBD54

# define RED_ORANGE_0	0x4B291D
# define RED_ORANGE_1	0x92391A
# define RED_ORANGE_2	0xE34F1C
# define RED_ORANGE_3	0xFB8A29
# define RED_ORANGE_4	0xFBDf47

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

# define BURNINGSHIP_0	0x4B291D
# define BURNINGSHIP_1	0x9F3B2B
# define BURNINGSHIP_2	0x92391A
# define BURNINGSHIP_3	0xC11D1D
# define BURNINGSHIP_4	0xE34F1C
# define BURNINGSHIP_5	0xFB8A29
# define BURNINGSHIP_6	0xFBDf47
# define BURNINGSHIP_7	0xBA3B1B
# define BURNINGSHIP_8	0xDC501B
# define BURNINGSHIP_9	0xFC7411
# define BURNINGSHIP_10	0xFFAC1F
# define BURNINGSHIP_11	0x40405E
# define BURNINGSHIP_12	0x33335B
# define BURNINGSHIP_13	0x262662
# define BURNINGSHIP_14	0x1A1A60
# define BURNINGSHIP_15	0x0D0D5D

/*
**	Error messages
*/

# define ERR_NAME		"\033[31;1mError:\033[0m Fractal unavailable."
# define ERR_MALLOC		"\033[31;1mError :\033[0m Can't allocate memory."
# define ERR_FORK		"\033[31;1mError :\033[0m Can't fork the process."

#endif
