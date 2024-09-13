# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masoares <masoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 07:54:38 by masoares          #+#    #+#              #
#    Updated: 2024/01/16 12:36:02 by masoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread -g -fsanitize=thread

NAME = philo

SRCS = philo.c philo_errors.c philo_init.c philo_utils.c philo_finex.c \
		philo_utils_2.c philo_utils_3.c

BONUS_SRCS = 

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

fclean: clean
		rm -f $(NAME)
clean:
		rm -f $(OBJS) $(BONUS_OBJS)

re: fclean all
