/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:49:40 by kibotrel          #+#    #+#             */
/*   Updated: 2019/04/23 15:44:27 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static int	ft_index(const char *str, char c)
{
	int				i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_process_line(char **save, char **line, int length, int n)
{
	char			*tmp;

	tmp = *save;
	if ((tmp != NULL || n < 0) && (!(*line = ft_strsub(*save, 0, length))))
		return (-1);
	if (tmp && tmp[length] == '\n')
		length++;
	if (tmp && tmp[length])
		*save = ft_strdup(tmp + length);
	else
		*save = NULL;
	n = (tmp != NULL || n > 0);
	free(tmp);
	return (n);
}

static int	ft_fd_line(const int fd, char **line, char **save)
{
	int				n;
	int				length;
	char			*tmp;
	char			str[BUFF_SIZE + 1];

	while ((length = ft_index(*save, '\n')) == ft_index(*save, '\0'))
	{
		if ((n = read(fd, str, BUFF_SIZE)) < 0)
			return (-1);
		if (n == 0)
			break ;
		str[n] = '\0';
		if (!(tmp = ft_strjoin(*save ? *save : "", str)))
			return (-1);
		free(*save);
		*save = tmp;
	}
	return (ft_process_line(save, line, length, n));
}

static void	ft_gnlist_del(t_gnlist **cyclehit)
{
	t_gnlist	*tmp;

	tmp = *cyclehit;
	*cyclehit = tmp->next;
	if (*cyclehit == tmp)
		*cyclehit = NULL;
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	free(tmp);
}

int			ft_get_next_line(const int fd, char **line)
{
	int				n;
	t_gnlist		*current;
	static t_gnlist *cyclehit = NULL;

	n = 0;
	current = cyclehit;
	while (cyclehit && (!n || current != cyclehit) && cyclehit->fd != fd
			&& (n = 1))
		cyclehit = cyclehit->next;
	if (!cyclehit || cyclehit->fd != fd)
	{
		if (!(current = (t_gnlist*)malloc(sizeof(*current))))
			return (-1);
		current->next = (cyclehit ? cyclehit->next : current);
		current->prev = (cyclehit ? cyclehit : current);
		current->next->prev = current;
		current->prev->next = current;
		current->save = NULL;
		cyclehit = current;
		cyclehit->fd = fd;
	}
	if ((n = ft_fd_line(cyclehit->fd, line, &cyclehit->save)) == 0)
		ft_gnlist_del(&cyclehit);
	return (n);
}
