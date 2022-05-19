/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/19 18:56:17 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINAL_H
# define FT_TERMINAL_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_terminal
{
	char				*title;
	char				**history;
}	t_terminal;


void	ft_handler(int sig);
void	init_keys(void);
int		ft_new_terminal(char **envp);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_check_path(char *path, char *cmd, int i, int j);
char	*ft_get_path(char *path, char *cmd);
int		execute(char **cmd, char **envp);
void	ft_read_command(char *cmd, char **envp);
char	*ft_display_prompt(char *line);
void	ft_free_matrix(char **matrix);

#endif
