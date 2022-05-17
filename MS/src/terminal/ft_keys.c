/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:03:52 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/17 17:28:21 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_terminal.h>

void	ft_handler(int sig)
{
	printf("signo: %i\n", sig);
	if (sig == SIGINT)
		exit(0);
}

void	init_keys(void)
{
	struct sigaction	action;

	action.sa_handler = ft_handler;
	sigaction(SIGINT, &action, NULL);
	printf("init_keys: %i\n", getpid());
}
