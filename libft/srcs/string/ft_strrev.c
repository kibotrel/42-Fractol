/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 00:32:33 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 16:04:14 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	tmp;

	i = -1;
	size = 0;
	while (str[size])
		size++;
	size--;
	while (++i < size)
	{
		tmp = str[i];
		str[i] = str[size];
		str[size--] = tmp;
	}
	return (str);
}
