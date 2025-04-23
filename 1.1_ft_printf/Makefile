# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpinho-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 14:55:53 by cpinho-c          #+#    #+#              #
#    Updated: 2024/12/11 14:56:08 by cpinho-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c printf_char.c printf_digits.c printf_str.c \
	   printf_uns.c printf_hex.c printf_ptr.c
	
OBJS = $(SRCS:.c=.o)
RM = rm -rf
LIBFT = libft/libft.a

.SILENT:

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS) libft/*.o

$(LIBFT): libft
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
