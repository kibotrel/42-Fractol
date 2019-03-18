/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:01:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 02:14:45 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "libft.h"
#include "env.h"
#include "fractol.h"

void		hud_background(t_env *env)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= HEIGHT)
	{
		x = 799;
		while (++x <= WIDTH)
		{
			if (y < 50 || (y >= 400 && y < 450))
				pixel_to_image(env, x, y, 0x23272A);
			else
				pixel_to_image(env, x, y, 0x2C2F33);
		}
	}
}

static void	fill_fields(t_infos *i, t_env *env)
{
	double	mix;
	double	miy;
	double	max;
	double	may;

	mix = env->x_min + (float)env->cam->offset_y;
	miy = env->y_min + (float)env->cam->offset_x;
	max = env->x_max + (float)env->cam->offset_y;
	may = env->y_max + (float)env->cam->offset_x;
	sprintf(i->checks, "Iterations    : %d", env->checks);
	if (env->zoom_count < ZOOM_MAX)
		sprintf(i->zoom, "Zoom          : x%.2f", env->cam->zoom);
	sprintf(i->c, "%+.5f %+.5fi", env->julia_x, env->julia_y);
	sprintf(i->off_x, "Offset X      : %.2f", env->cam->offset_y);
	sprintf(i->off_y, "Offset Y      : %.2f", env->cam->offset_x);
	sprintf(i->sound, "Sound name    : %s\n", env->sound_name);
	sprintf(i->region, "%+.5f %+.5fi to %+.5f %+.5fi", mix, miy, max, may);
}

static void	fractal_infos(void *id, void *win, t_env *env)
{
	t_infos i;

	fill_fields(&i, env);
	get_fractal_name(env->mlx->id, env->mlx->win, env);
	mlx_string_put(id, win, 1040, 15, WHITE, "Informations");
	mlx_string_put(id, win, 955, 100, WHITE, i.checks);
	if (ft_strlen(i.zoom) < LEN_ZOOM_MAX && env->zoom_count < ZOOM_MAX)
		mlx_string_put(id, win, 955, 120, WHITE, i.zoom);
	else
	{
		mlx_string_put(id, win, 955, 120, WHITE, "Zoom          :");
		mlx_string_put(id, win, 1115, 120, TRUE_RED, "Too big to fit in !");
	}
	mlx_string_put(id, win, 955, 140, WHITE, i.off_x);
	mlx_string_put(id, win, 955, 160, WHITE, i.off_y);
	infos_color(env, env->mlx->id, env->mlx->win);
	mlx_string_put(id, win, 955, 220, WHITE, i.sound);
	mlx_string_put(id, win, 1025, 260, WHITE, "Explored region");
	mlx_string_put(id, win, 900, 280, WHITE, i.region);
	if (env->fractal == JULIA || env->fractal == BURNING_JULIA)
	{
		mlx_string_put(id, win, 1030, 320, WHITE, "Preset complex");
		mlx_string_put(id, win, 1010, 340, WHITE, i.c);
	}
}

static void	fractal_controls(void *id, void *win)
{
	mlx_string_put(id, win, 1065, 415, WHITE, "Controls");
	mlx_string_put(id, win, 835, 480, WHITE, "Color Modes     : M");
	mlx_string_put(id, win, 1125, 480, WHITE, "Reset View      : R");
	mlx_string_put(id, win, 835, 500, WHITE, "Offset          : W/A/S/D");
	mlx_string_put(id, win, 1125, 500, WHITE, "Zoom            : Scroll");
	mlx_string_put(id, win, 970, 560, WHITE, "Details : Page_Up/Page_Down");
	mlx_string_put(id, win, 835, 620, WHITE, "Gradient Colors : V/B/N");
	mlx_string_put(id, win, 1125, 620, WHITE, "Area Colors     : Z/X/C");
	mlx_string_put(id, win, 835, 640, WHITE, "Config Julia    : Tilde");
	mlx_string_put(id, win, 1125, 640, WHITE, "Psycho mode     : P");
	mlx_string_put(id, win, 835, 660, WHITE, "Change sound    : J/K/L");
	mlx_string_put(id, win, 1125, 660, WHITE, "Select fractal  : 1/2/3/4");
	mlx_string_put(id, win, 970, 720, WHITE, "Quit : Escape / Windowcross");
	mlx_string_put(id, win, 1200, 765, WHITE, "Fractol by kibotrel");
}

void		hud_infos(t_env *env)
{
	fractal_infos(env->mlx->id, env->mlx->win, env);
	fractal_controls(env->mlx->id, env->mlx->win);
}
