/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:39:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/17 17:10:33 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static void	execute(t_terminal	*t, char	*line)
{
	char		**argv;
	t_command	*c;
	int			i;

	argv = string().split(line, ' ', 0, 0);
	i = 0;
	(void) t;
	while (argv && argv[i] && t->commands)
	{
		c = list(t->commands)->add(new_command(argv[i]));
		c->init(argv[i], data()->envp);
		i++;
	}
	pipe(t->fd);
	list(t->commands)->add(new_console(NULL));
	list(t->commands)->get(0)->input(t->fd);
	list(t->commands)->forEach(list_clear);
	close(t->fd[0]);
	close(t->fd[1]);
}

static void	ft_input(void)
{
	t_terminal	*t;
	char		*line;

	t = this()->terminal;
	if (!t)
		return ;
	while (1)
	{
		line = read_line(t);
		execute(t, line);
	}
}

t_terminal	*new_terminal(char *title)
{
	t_terminal	*t;

	t = malloc(sizeof(t_terminal));
	if (!t)
		return (0);
	t->input = ft_input;
	t->title = title;
	t->commands = new_list();
	this()->terminal = t;
	return (t);
}
