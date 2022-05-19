/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:44:06 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/19 18:58:42 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_terminal.h>


int	execute(char **cmd, char **envp)
{	
	int	pid;

	pid = fork();
	if (!pid)
		if (execve(ft_get_path(getenv("PATH"), *cmd), cmd, envp) == -1)
			write(1, "error in execve\n", 16);
	waitpid(pid, NULL, 0);
	return (0);
}

void	ft_read_command(char *cmd, char **envp)
{
	char	**cmds;
	//char	**command;

	// ft_split retorna uma array de strings com todos os commandos (exemplo: ls -l && cat file.c)
	cmds = ft_split(cmd, ' ');
	while (cmds && *cmds)
	{
		// ft_get_cmd retorna uma array de string em que só estao os commandos que têm que funcionar juntos (exemplo: ls -l)
		//command = ft_get_cmd(cmds);
		// ft_del_cmd vai retornar uma array de strings mas sem os commandos que estão em command (cmds - command)
		//cmds = ft_del_cmd(cmds, command);
		// execute vai executar um grupo de comandos
		execute(cmds, envp);
		ft_free_matrix(cmds);
		cmds = NULL;
	}
}
