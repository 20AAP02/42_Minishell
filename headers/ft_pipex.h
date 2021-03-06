/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/17 13:41:23 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <ft_command.h>
# include <ft_string.h>
# include <ft_terminal.h>
# include <ft_this.h>
# include <ft_read_line.h>

# define FD_WRITE_O 1
# define FD_READ_O 0

typedef int	t_pid;

typedef struct s_pipex
{
	char				out_input[BUFFER_SIZE];
	int					fd_read_original;
	int					fd_write_original;
	int					fd[2];
	int					size_read;
	char				**envp;
	char				*path;
	int					i;
	pid_t				pid;
	pid_t				pid_base;
	t_command			*lis[10];
	int					teste;
}	t_pipex;

typedef struct s_item
{
	char		*path;
	char		**item;
}	t_item;

void		instance_fork(t_command *cmd, int id, int fork_max, t_pipex	*p);

//			UTIL
void		close_program(t_command *cmd, t_pipex	*p);
void		out_input(t_command *cmd, t_pipex	*p, int id, int max);
t_pipex		*data(void);
t_command	*new_command(char *arg);
t_command	*new_console(char *arg);
char		*get_path(t_command	*c, char *arg, const char *path);

//			TESTE
t_command	ls(void);
t_command	wc(void);
t_command	df(void);
void		printf_cmd(t_command **c);
void		init_keys(void);

#endif
