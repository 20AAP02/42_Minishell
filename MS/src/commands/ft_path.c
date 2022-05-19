/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:41:37 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/19 18:42:58 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_terminal.h>

char	*ft_check_path(char *path, char *cmd, int i, int j)
{
	char	*str;
	char	*mem;

	str = malloc(sizeof(char) * (j - i + 1));
	ft_strlcpy(str, path + i, j - i + 1);
	mem = str;
	str = ft_strjoin(str, "/");
	free(mem);
	mem = str;
	str = ft_strjoin(str, cmd);
	free(mem);
	if (access(str, 0) != -1)
		return (str);
	free(str);
	return (NULL);
}

char	*ft_get_path(char *path, char *cmd)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (path && path[i])
	{
		j = i;
		while (path[j] && path[j] != ':')
			j++;
		str = ft_check_path(path, cmd, i, j);
		if (str)
			return (str);
		j++;
		i = j;
	}	
	return (NULL);
}
