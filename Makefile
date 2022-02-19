# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:32:31 by fbouanan          #+#    #+#              #
#    Updated: 2022/02/15 17:32:34 by fbouanan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

all : $(NAME)

server: 
	gcc -Wall -Werror -Wextra server.c minitalk_utils.c minitalk_utils2.c -o server

client:
	gcc -Wall -Werror -Wextra client.c minitalk_utils.c minitalk_utils2.c -o client

clean :
	rm -f $(NAME)
fclean : clean

re : fclean all
