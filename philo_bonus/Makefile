# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masoares <masoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 07:54:38 by masoares          #+#    #+#              #
#    Updated: 2024/01/16 12:52:37 by masoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread -g -fsanitize=thread

NAME = philo_bonus

SRCS = philo_bonus.c philo_errors_bonus.c philo_init_bonus.c philo_utils_bonus.c \
		philo_utils_2_bonus.c philo_utils_3_bonus.c philo_utils_4_bonus.c
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
