/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:01:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/17 12:44:34 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

char	*get_path(t_command	*c, char *arg, const char *path)
{
	int		i[2];

	i[0] = 0;
	path = path + 5;
	while (path && *path)
	{
		i[1] = 0;
		c->path[i[0]] = *path++;
		if (c->path[i[0]] && c->path[i[0]] != ':' && i[0]++ < 100)
			continue ;
		c->path[i[0]++] = '/';
		while (arg && arg[i[1]] && arg[i[1]] != ' ' && arg[i[1]] != '\t')
			c->path[i[0]++] = arg[i[1]++];
		c->path[i[0]] = 0;
		if (access(c->path, F_OK) == -1)
			i[0] = 0;
		else
			break ;
	}
	if (access(c->path, F_OK) == -1)
		c->path[0] = 0;
	return (NULL);
}
