/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:19:22 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 16:23:05 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_charcount(char *str, char c)
{
	int	counter;

	counter = 0;
	while (str && *str)
		if (*str++ == c)
			counter++;
	return (counter);
}
