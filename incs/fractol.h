/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:14:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/08 05:14:59 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_img
{
	int			bpp;
	int			size;
	int			endian;
	void		*id;
	char		*data;
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
	int			shift;
	int			color;
	double		offset_y;
	double		offset_x;
}				t_cam;

typedef struct	s_env
{
	int			child;
	int			checks;
	int			fractal;
	int			base_color;
	int			palette[16];
	t_mlx		*mlx;
	t_cam		*cam;
	double		julia_y;
	double		julia_x;

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
	int			n;
	double		y;
	double		x;
	double		z_y;
	double		z_x;
	double		cur_y;
	double		cur_x;
	double		strt_y;
	double		strt_x;
}				t_par;
/*
**	setup.c
*/

t_env			*initialize(int fractal);

/*
**	hooks.c
*/

void			hooks(t_env *env);

/*
**	utils.c
*/

void			free_all(t_env *env);
void			kill_process_id(void);
t_map			fill_data(double start, double end, double min, double max);
double			map(double n, t_map m);

/*
**	selector.c
*/

void			color_preset(t_env *env);
void			draw_fractal(t_env *env);

/*
**	mandelbrot.c
*/

void			mandelbrot(t_env *env);

/*
**	image.c
*/

void			new_img(t_env *env);
void			pixel_to_image(t_env *env, int x, int y, int color);

/*
**	color.c
*/

int				color(t_par data, t_env *env);
void			color_mode(t_env *env);
void			colorset(t_env *env, int key);
void			base_color(t_env *env, int key);

/*
**	maths.c
*/

double			mod(double a, double b);
double			real_part(double a, double b);
double			imaginary_part(double a, double b);
double			ratio(int start, int end, int current);

/*
**	process_input.c
*/

void			reset(t_env *env);
void			psycho_effect(t_env *env);
void			offset(t_env *env, int key);
void			details(t_env *env, int key);

/*
**	colorset.c
*/

void			set1(t_env *env);
void			set2(t_env *env);
void			set3(t_env *env);
void			shift_color(t_env *env);
void			shift_default(t_env *env);

/*
**	preset.c
*/

void			mandelbrot_color(t_env *env);

/*
**	julia.c
*/

void			julia(t_env *env);

#endif
