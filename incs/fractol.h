/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:14:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/22 19:22:16 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_img
{
	void		*id;
	char		*data;
	int			bpp;
	int			size;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*id;
	void		*win;
	t_img		*img;
}				t_mlx;

typedef struct	s_cam
{
	int			hud;
	int			zoom;
	int			offset_y;
	int			offset_x;
}				t_cam;

typedef struct	s_env
{
	t_mlx		*mlx;
	t_cam		*cam;
	int			fractal;
}				t_env;

typedef struct	s_map
{
	double		in_s;
	double		in_e;
	double		out_s;
	double		out_e;
}				t_map;

typedef struct	s_par
{
	double		y;
	double		x;
	double		z_y;
	double		z_x;
	double		cur_y;
	double		cur_x;
	double		strt_y;
	double		strt_x;
	int			n;
}				t_par;
/*
**	setup.c
*/

t_env			*initialize(int fractal);

/*
**	selector.c
*/

/*
**	hooks.c
*/

void			hooks(t_env *env);

/*
**	utils.c
*/

double			pow2(double n);
double			map(double n, t_map m);
t_map			fill_params(double start, double end, double min, double max);
void			free_all(t_env *env);

/*
**	selector.c
*/

void			draw_fractal(t_env *env);

/*
**	mandelbrot.c
*/

void			mandelbrot(t_env *env);

/*
**	image.c
*/

void			pixel_to_image(t_env *env, int x, int y, int color);

#endif
