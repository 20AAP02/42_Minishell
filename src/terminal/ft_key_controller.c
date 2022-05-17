/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:03:52 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/17 14:22:28 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <ft_this.h>

static void	server_list(int signo, siginfo_t *i, void *context)
{
	(void) context;
	(void) i;
	printf("signo: %i\n", signo);
	if (signo == SIGINT)
		exit(0);
	if (signo == SIGSEGV)
	{
		write(1, "seg fault SEU VIADO\n", 20);
		exit(0);
	}
}

void	init_keys(void)
{
	t_pid				id;
	struct sigaction	usr_action;
	sigset_t			block_mask;

	(void) id;
	sigemptyset(&block_mask);
	usr_action.sa_mask = block_mask;
	sigaddset(&usr_action.sa_mask, SIGUSR1);
	sigaddset(&usr_action.sa_mask, SIGUSR2);
	usr_action.sa_flags = SA_SIGINFO;
	usr_action.sa_sigaction = server_list;
	sigaction(SIGQUIT, &usr_action, NULL);
	sigaction(SIGINT, &usr_action, NULL);
	// teste
	sigaction(SIGSEGV, &usr_action, NULL);
	id = getpid ();
	printf ("init_keys: %i\n", id);
}
