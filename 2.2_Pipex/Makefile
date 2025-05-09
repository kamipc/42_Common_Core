# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpinho-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 14:26:36 by cpinho-c          #+#    #+#              #
#    Updated: 2025/05/06 14:26:40 by cpinho-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = pipex.c utils/checks.c utils/tasks.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBFT = libft/libft.a

.SILENT:

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean all