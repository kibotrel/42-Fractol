/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:14:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/21 18:46:39 by kibotrel         ###   ########.fr       */
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

void			free_all(t_env *env);

#endif
