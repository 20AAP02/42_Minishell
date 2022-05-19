/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:50:38 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/19 18:55:18 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_terminal.h>

char	*ft_display_prompt(char *line)
{
	char	*mem;
	char 	a[2];

	a[0] = 0;
	a[1] = 0;
	line = NULL;
	read(1, a, 1);
	while (a[0] != '\n')
	{
		if (a[0] == 0 && line == NULL)
			exit(0);
		mem = ft_strjoin(line, a);
		read(1, a, 1);
		if (line && *line)
			free(line);
		line = mem;
	}
	return (line);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	if (matrix)
		free(matrix);
}

int	ft_new_terminal(char **envp)
{
	char	*command_line;
	//char	**history;

	command_line = NULL;
	while (1)
	{
		write(1, "bash-3.2$ ", 10);
		command_line = ft_display_prompt(command_line);
		ft_read_command(command_line, envp);
		if (command_line && *command_line)
			free(command_line);
	}
	return (0);
}