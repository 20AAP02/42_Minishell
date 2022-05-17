/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:37:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/17 12:42:14 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <ft_this.h>

static int	*ft_input(int fd[2])
{
	t_command	*input;

	if (!this()->list || !this()->list->this)
		return (fd);
	input = this()->list->this;
	pipe(input->fd);
	if (input->execute(input, fd[0], input->fd[1]))
	{
		this()->list->this = input->next;
		this()->list->this->input(input->fd);
		close(fd[0]);
		close(fd[1]);
	}
	return (input->fd);
}

static int	execute(t_command *cmd, int input, int out)
{
	pid_t	pit;

	pit = fork();
	if (!pit)
	{
		if (dup2(input, 0) < 0 || dup2(out, 1) < 0 || \
		close(input) || close(out))
			exit(0);
		execve(cmd->path, cmd->commands, data()->envp);
		return (0);
	}
	waitpid(pit, NULL, 0);
	data()->teste++;
	close(input);
	close(out);
	return (1);
}

static void	init(char *arg, char **envp)
{
	t_command	*c;
	char		*path;
	int			i;

	if (!this()->list || !this()->list->this)
		return ;
	c = this()->list->this;
		i = -1;
	while (envp[++i] && !string().contains(path, "PATH="))
		path = envp[i];
	c->commands = string().split(arg, ' ', 0, NULL);
	get_path(c, arg, path);
	return ;
}

t_command	*new_command(char *arg)
{
	t_command	*c;

	c = malloc(sizeof(t_command));
	if (!c)
	{
		printf("err: %s\n", "malloc");
		return (0);
	}
	c->input = ft_input;
	c->init = init;
	c->execute = execute;
	c->arg = arg;
	c->next = NULL;
	c->path[0] = 0;
	c->commands = NULL;
	c->pid = data()->pid_base++;
	return (c);
}
