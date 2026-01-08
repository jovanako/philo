# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 19:58:27 by jkovacev          #+#    #+#              #
#    Updated: 2026/01/07 17:26:03 by jkovacev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

SRCS := main.c \
	$(wildcard helpers/*.c) \
	$(wildcard lists/*.c) \
	$(wildcard input/*.c) \
	$(wildcard philosopher/*.c) \
	$(wildcard monitor/*.c) \
	$(wildcard simulation/*.c)

OBJDIR = objects
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

DEPS = helpers/*.h \
		lists/*.h \
		input/*.h \
		philosopher/*.h \
		monitor/*.h \
		simulation/*.h

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re