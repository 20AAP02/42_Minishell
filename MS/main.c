/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:12:15 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/17 18:51:08 by amaria-m         ###   ########.fr       */
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
	return (0);
}