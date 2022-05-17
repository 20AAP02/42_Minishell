/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:26:36 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/17 12:46:06 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

t_list_cmd	*list(t_list_cmd *t)
{
	this()->list = t;
	return (this()->list);
}

void	list_clear(t_command **c)
{
	int	i;

	i = 0;
	if (c && *c)
	{
		while ((*c)->commands && (*c)->commands[i])
			free((*c)->commands[i++]);
		if ((*c)->commands)
			free((*c)->commands);
		free((*c));
		*c = NULL;
	}
}
