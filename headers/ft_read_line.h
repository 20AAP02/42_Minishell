/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/17 13:41:14 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_LINE_H
# define FT_READ_LINE_H

# include <stdlib.h>
# include <ft_base_array.h>

typedef struct s_read	t_read;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 999999
# endif

struct s_read
{
	t_array			*lines;
	t_array			*history;

};

t_read	*new_read_line(void);
char	*read_line(t_terminal *t);

#endif
