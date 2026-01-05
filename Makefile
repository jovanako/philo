# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 19:58:27 by jkovacev          #+#    #+#              #
#    Updated: 2026/01/05 18:13:52 by jkovacev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

SRCS = philo.c \
		ft_atol.c \
		helpers.c \
		lists1.c \
		threads.c \
		create_philo.c

OBJDIR = objects
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

DEPS = philo.h

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re