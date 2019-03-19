/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:52:03 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/18 15:31:33 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ratio(int start, int end, int current)
{
	double	pos;
	double	distance;

	pos = current - start;
	distance = end - start;
	return (distance == 0 ? 1.0 : pos / distance);
}
