/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psycho_effect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:01:32 by kibotrel          #+#    #+#             */
/*   Updated: 2019/03/28 01:35:43 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "env.h"
#include "fractol.h"

void	kill_process_id(void)
{
	int		fd;
	char	*line;
	char	command[32];

	system("pidof afplay > test");
	fd = open("test", O_RDONLY);
	ft_get_next_line(fd, &line);
	close(fd);
	if (line)
	{
		sprintf(command, "kill %d", ft_atoi(line));
		system(command);
		free(line);
	}
	system("rm -f test");
}

void	psycho_effect(t_env *env)
{
	char	command[64];

	sprintf(command, "afplay -q 1 %s", env->sound_name);
	if (!env->child)
		env->child = fork();
	if (env->child == -1)
		ft_print_error(ERR_FORK, 3);
	else if (env->child > 0)
	{
		if (!env->cam->shift)
			shift_default(env);
		else
			shift_color(env);
		threads(env, env->mlx->id, env->mlx->win, env->mlx->img->id);
	}
	else if (env->child == 0)
		while (1)
			system(command);
}
