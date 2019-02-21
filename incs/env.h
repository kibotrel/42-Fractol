/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:14:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/21 18:36:58 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Minilibx informations
*/

# define WIDTH 800
# define TITLE "[Minilibx Project] Fractol 42"
# define HEIGHT 600

/*
**	Available fractals
*/

# define MANDELBROT 1

/*
**	Used keycodes to communicate with mlx
*/

# define ESC 53

/*
**	Error messages
*/

# define ERR_NAME "\033[31;1mError:\033[0m Fractal unavailable."
# define ERR_MALLOC "\033[31;1mError :\033[0m Can't allocate memory."

#endif
