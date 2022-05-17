/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/17 12:42:32 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*input(int fd[2])
{
	char	buffer[BUFFER_SIZE];

	dup2(fd[1], 1);
	close(fd[1]);
	buffer[read(fd[0], buffer, BUFFER_SIZE)] = 0;
	if (this()->list && this()->list->this)
		this()->list->this = this()->list->this->next;
	printf("%s", buffer);
	close(fd[0]);
	return (fd);
}

static int	ft_execute(t_command *cmd, int input, int out)
{
	(void) cmd;
	(void) input;
	(void) out;
	return (1);
}

t_command	*new_console(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = input;
	c->execute = ft_execute;
	return (c);
}
