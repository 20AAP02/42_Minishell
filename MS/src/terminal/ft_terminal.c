/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:50:38 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/18 21:09:21 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_terminal.h>

typedef struct s_terminal
{
	char				*title;
	char				**history;
	struct s_terminal	*next;
}	t_terminal;

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	new_str = malloc(i + j + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = 0;
	return (new_str);
}

static char	*ft_display_prompt(char *line)
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

static void	ft_read_command(char *cmd)
{
	char	**cmds;
	int		i;

	cmds = ft_split(cmd, ' ');
	i = 0;
	while (cmds[i])
	{
		printf("%s\n", cmds[i]);
		i++;
	}
	i = 0;
	while (cmds[i])
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

int	ft_new_terminal()
{
	char	*command_line;
	int		check;

	check = 1;
	while (check)
	{
		write(1, "bash-3.2$ ", 10);
		command_line = ft_display_prompt(command_line);
		ft_read_command(command_line);
		if (command_line && *command_line)
			free(command_line);
	}
	return (0);
}