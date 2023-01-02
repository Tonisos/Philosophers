# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:56:53 by amontalb          #+#    #+#              #
#    Updated: 2023/01/02 14:20:01 by amontalb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADERS = philo.h

SOURCES = *.c
	
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

all :    $(NAME)

$(NAME) : $(OBJECTS)
	${CC} ${CFLAG} -o $@ $^
	
%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS) 

fclean : clean 
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re 