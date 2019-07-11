/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:29:20 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/24 15:31:06 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isvalidname(char *filename, char *reference)
{
	int	i;
	int	j;

	i = ft_strlen(filename) - 1;
	j = ft_strlen(reference) - 1;
	while (j >= 0)
		if (filename[i--] != reference[j--])
			return (0);
	return (i >= 0 ? 1 : 0);
}
