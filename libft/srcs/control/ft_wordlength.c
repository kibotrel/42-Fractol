/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlength.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 01:49:34 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 16:24:41 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wordlength(char const *s, int i, char c)
{
	int length;

	length = 0;
	while (s[i] && s[i] != c)
	{
		length++;
		i++;
	}
	return (length);
}
