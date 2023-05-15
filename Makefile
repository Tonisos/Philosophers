# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 10:56:05 by amontalb          #+#    #+#              #
#    Updated: 2023/03/29 17:20:46 by amontalb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADERS = philo.h

SOURCES = main.c utils.c utils2.c init.c exit.c routine.c
	
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -pthread -g3 -I .

all : 
	$(MAKE) $(NAME)

$(NAME) : $(OBJECTS)
	${CC} $^ ${CFLAGS} -o $@
	
%.o : %.c $(HEADERS) 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS) 

fclean : clean 
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re 