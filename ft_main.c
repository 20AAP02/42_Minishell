/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/17 13:04:46 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

t_pipex	*data(void)
{
	static t_pipex	data;

	return (&data);
}

void	free_cmd(t_command **c)
{
	int	i;

	i = 0;
	if (c && *c)
	{
		while ((*c)->commands && (*c)->commands[i])
			free((*c)->commands[i++]);
		if ((*c)->commands)
			free((*c)->commands);
		free(*c);
		*c = NULL;
	}
}

void	printf_cmd(t_command **c)
{
	char	**temp;

	if (c && (*c) && (*c)->commands)
	{	
		printf("==============\n");
		printf("path: %s\n", (*c)->path);
		printf("commands: ");
		temp = (*c)->commands;
		while (*temp)
			printf("%s ", *temp++);
		printf("\n");
	}
	else
		printf("commands: %s\n", "command error\n");
}

// -fsanitize=address -g

int	main(int argc, char **argv, char **envp)
{
	t_terminal	*t;

	(void) argc;
	(void) argv;
	data()->envp = envp;
	data()->teste = 1;
	data()->pid_base = 100;
	init_keys();
	new_read_line();
	t = new_terminal("bash-3.2$ ");
	t->input();
}
