/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:33:09 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/08 05:21:52 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "env.h"
#include "fractol.h"


char	*get_command(char *command, int id)
{
	int				i;
	char			*value;
	char			*tmp;
	char			*newcommand;
	unsigned int	size;

	size = ft_strlen(command);
	i = 0;
	newcommand = (char*)malloc(sizeof(char) * (size + 1));
	while (*command != '\0')
		newcommand[i++] = *command++;
	newcommand[i] = '\0';
	tmp = ft_itoa_base(id, 10);
	value = ft_strjoin(newcommand, tmp);
	free(newcommand);
	free(tmp);
	return (value);
}

void	kill_process_id(void)
{
	int		fd;
	char	*line;
	char	*newcommand;

	system("pidof afplay > test");
	fd = open("test", O_RDONLY);
	ft_get_next_line(fd, &line);
	close(fd);
	if (line)
	{
		system(newcommand = get_command("kill ", ft_atoi(line)));
		free(newcommand);
		free(line);
	}
	system("rm -f test");
}

void	free_all(t_env *env)
{
	free(env->mlx->img);
	free(env->mlx);
	free(env->cam);
	free(env);
}

t_map	fill_data(double start, double end, double min, double max)
{
	t_map	tmp;

	tmp.in_s = start;
	tmp.in_e = end;
	tmp.out_s = min;
	tmp.out_e = max;
	return (tmp);
}

double	map(double n, t_map m)
{
	return ((n - m.in_s) / (m.in_e - m.in_s) * (m.out_e - m.out_s) + m.out_s);
}
