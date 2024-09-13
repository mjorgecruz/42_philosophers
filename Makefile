# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masoares <masoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 12:55:02 by masoares          #+#    #+#              #
#    Updated: 2024/01/16 17:14:41 by masoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./philo/philo

NAME_BONUS = ./philo_bonus/philo_bonus

all: $(NAME)

$(NAME):
	make -C ./philo
	
bonus: $(NAME_BONUS)

$(NAME_BONUS):
	make -C ./philo_bonus

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_BONUS)
clean:
		make clean -C ./philo
		make clean -C ./philo_bonus

re: fclean all