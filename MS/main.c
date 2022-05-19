/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:12:15 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/19 12:59:16 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_terminal.h>

// getenv to acess enviroment variables

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	
	init_keys();
	ft_new_terminal();
	//printf("%s\n", getenv("PATH"));
	return (0);
}