# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpinho-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 14:55:59 by cpinho-c          #+#    #+#              #
#    Updated: 2025/05/18 14:56:01 by cpinho-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c utils/checks.c utils/errors.c utils/map_checks.c \
	   utils/inits.c utils/map_ff_check.c 
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBFT = libft/libft.a

.Silent:

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

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