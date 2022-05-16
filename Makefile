# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2022/05/01 17:15:46 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_main.c	\
				./src/commands/ft_command.c  \
				./src/commands/ft_console.c  \
				./src/terminal/ft_terminal.c  \
				./src/terminal/ft_read_line.c  \
				./src/terminal/ft_key_controller.c  \
				./src/util/list/ft_list_cmd.c  \
				./src/util/list/ft_list.c  \
				./src/util/ft_string.c \
				./src/util/ft_util.c \
				./src/util/ft_this.c \
				./src/util/array/ft_base_array.c \
				./src/util/array/ft_base_array_util.c \

OBJS		= 	$(SRCS:.c=.o)
CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	minishell
INCLUDE		= 	./headers

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

bonus: all

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader $(SRCS)

m: fclean

.PHONY: all re clean fclean m
