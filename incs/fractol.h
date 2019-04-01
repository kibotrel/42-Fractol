/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:14:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/01 17:26:59 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>

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
	int			shift;
	int			color;
	double		zoom;
	double		offset_y;
	double		offset_x;
}				t_cam;

typedef struct	s_menu
{
	int			sound;
	int			checks;
	int			palette;
	int			fractal;
	int			colormode;
	int			base_color;
}				t_menu;

typedef struct	s_env
{
	int			child;
	int			checks;
	int			fractal;
	int			base_color;
	int			zoom_count;
	int			palette[16];
	int			menu_window;
	int			toggle_julia;
	int			current_level;
	char		*sound_name;
	t_mlx		*mlx;
	t_cam		*cam;
	t_menu		menu;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	double		julia_y;
	double		julia_x;
	pthread_t	threads[32];

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

typedef struct	s_infos
{
	char		c[32];
	char		zoom[128];
	char		off_x[32];
	char		off_y[32];
	char		sound[64];
	char		checks[32];
	char		region[64];
}				t_infos;

typedef struct	s_line
{
	int			error;
	int			offset;
	int			sign_y;
	int			sign_x;
	int			delta_y;
	int			delta_x;
}				t_line;

typedef struct	s_pos
{
	int			y;
	int			x;
}				t_pos;

typedef struct	s_posd
{
	double		y;
	double		x;
}				t_posd;
/*
** ./usage/usage.c
*/

int				usage(void);
void			fractal_list(void);

/*
** ./core/selector.c
*/

void			draw_fractal(t_env *env);
void			fractal_to_window(t_env *env);

/*
**	./core/threads.c
*/

void			threads(t_env *env, void *id, void *win, void *img);

/*
**	./parsing/parsing.c
*/

int				valid_fractal(char *name);

/*
**	./setup/setup.c
*/

t_env			*initialize(int fractal);

/*
**	./setup/color_preset.c
*/

void			color_preset(t_env *env);
void			set_base_color(t_env *env);
void			mandelbrot_julia_color(t_env *env);

/*
**	./setup/set_checks.c
*/

void			set_checks(t_env *env);

/*
**	./setup/set_bounds.c
*/

void			set_bounds(t_env *env);

/*
**	./setup/set_menu_params.c
*/

void			set_menu_params(t_env *env);

/*
**	./setup/set_fractal_params.c
*/

void			set_fractal_params(t_env *env);

/*
**	./fractals/mandelbrot.c
*/

void			mandelbrot(t_env *env, int thread);

/*
**	./fractals/julia.c
*/

void			julia(t_env *env, int thread);

/*
**	./fractals/burning_ship.c
*/

void			burning_ship(t_env *env, int thread);

/*
**	./fractals/burning_julia.c
*/

void			burning_julia(t_env *env, int thread);

/*
**	./fractals/sierpinski.c
*/

void			sierpinski(t_env *env);

/*
**	./fractals/koch.c
*/

void			koch(t_env *env);

/*
**	./fractal/barnsley.c
*/

void			barnsley(t_env *env);

/*
**	./fractal/flower.c
*/

void			flower(t_env *env);

/*
**	./events/change_fractal.c
*/

void			change_fractal(t_env *env, int key);

/*
**	./events/change_sound.c
*/

void			change_sound(t_env *env, int key);

/*
**	./events/shift_palettes.c
*/

void			shift_color(t_env *env);
void			shift_default(t_env *env);

/*
**	./events/update_colors.c
*/

void			color_mode(t_env *env);
void			colorset(t_env *env, int key);
void			base_color(t_env *env, int key);

/*
**	./events/offset.c
*/

void			offset(t_env *env, int key);

/*
**	./events/details.c
*/

void			details(t_env *env, int key);

/*
**	./events/reset.c
*/

void			reset(t_env *env);

/*
**	./events/psycho_effect.c
*/

void			psycho_effect(t_env *env);
void			kill_process_id(char *sound, t_env *env);

/*
**	./events/zoom.c
*/

void			keyboard_zoom(t_env *env, int key);
void			zoom_mouse(int direction, double x, double y, t_env *env);

/*
** ./events/quit.c
*/

int				red_cross(void *env);

/*
** ./maths/complex.c
*/

double			mod(double a, double b);
double			real_part(double a, double b);
double			imaginary_part(double a, double b);

/*
**	./maths/normalize.c
*/

t_map			fill_data(double start, double end, double min, double max);
double			map(double n, t_map m);

/*
**	./maths/update_bounds.c
*/

void			update_bounds(t_env *env);

/*
**	./maths/ratio.c
*/

double			ratio(int start, int end, int current);

/*
**	./maths/functions.c
*/

int				pow2(int x);
int				absolute(int x);

/*
**	./utils/draw_line.c
*/

void			draw_line(t_pos a, t_pos b, t_env *env);

/*
**	./utils/image.c
*/

void			new_img(t_env *env);
void			pixel_to_image(t_env *env, int x, int y, int color);

/*
**	./utils/color.c
*/

int				color(t_par data, t_env *env);
void			set1(t_env *env);
void			set2(t_env *env);
void			set3(t_env *env);

/*
**	./utils/clean.c
*/

void			free_all(t_env *env, int state);
void			destroy_threads(t_env *env, int threads);

/*
**	./utils/selected_settings.c
*/

void			color_selected_settings(void *id, void *win, t_menu menu);

/*
**	./hud/hud.c
*/

void			hud_infos(t_env *env);
void			hud_background(t_env *env);

/*
**	./hud/infos_colors.c
*/

void			infos_color(t_env *env, void *id, void *win);

/*
**	./hud/infos_controls.c
*/

void			fractal_controls(void *id, void *win);

/*
**	./hud/infos_complex.c
*/

void			infos_complex(t_env *env, void *id, void *win, t_infos i);

/*
**	./hud/infos_zoom.c
*/

void			infos_zoom(t_env *env, void *id, void *win, t_infos i);

/*
**	./hud/fractal_name.c
*/

void			get_fractal_name(void *mlx, void *win, t_env *env);

/*
**	./menu/menu.c
*/

void			menu(t_env *env, void *id, void *win, void *img);

/*
**	./menu/infos_menu.c
*/

void			main_menu_infos(void *id, void *win, int status);
void			selection_menu_infos(void *id, void *win, int status);
void			settings_menu_infos(void *id, void *win, int status, t_menu m);

/*
**	./menu/animations_menu.c
*/

void			main_menu_animations(int x, int y, void *id, void *win);
void			selection_menu_animations(int x, int y, void *id, void *win);
void			settings_menu_animations(int x, int y, t_mlx *mlx, t_menu menu);

/*
**	./menu/interactions_menu.c
*/

void			main_menu_interactions(int x, int y, t_env *env);
void			settings_menu_interactions(int x, int y, t_env *env);
void			selection_menu_interactions(int x, int y, t_env *env);

/*
**	./menu/hover_settings.c
*/

void			hover_sound_settings(int x, t_mlx *mlx, t_menu menu);
void			hover_details_settings(int x, t_mlx *mlx, t_menu menu);
void			hover_color_settings(int x, int y, t_mlx *mlx, t_menu menu);

/*
**	./menu/click_settings.c
*/
void			click_sound_settings(int x, t_env *env);
void			click_details_settings(int x, t_env *env);
void			click_color_settings(int x, int y, t_env *env);
/*
**	./hook/hooks.c
*/

void			hooks(t_env *env);

/*
**	./hook/fractal_hooks.c
*/

void			fractal_key_press(int key, t_env *env);
void			fractal_mouse_move(int x, int y, t_env *env);
void			fractal_mouse_press(int button, int x, int y, t_env *env);

/*
**	./hook/menu_hooks.c
*/

void			menu_key_press(int key, t_env *env);
void			menu_mouse_move(int x, int y, t_env *env);
void			menu_mouse_press(int button, int x, int y, t_env *env);

#endif
