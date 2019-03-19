/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:25:43 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 09:26:17 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	mod(double a, double b)
{
	return (a * a + b * b);
}

double	real_part(double a, double b)
{
	return (a * a - b * b);
}

double	imaginary_part(double a, double b)
{
	return (2 * a * b);
}
