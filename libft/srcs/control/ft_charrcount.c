/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charrcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:20:13 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 16:23:10 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_charrcount(char *str, char c)
{
	int	counter;

	counter = 0;
	while (str && *str)
		if (*str++ != c)
			counter++;
	return (counter);
}
