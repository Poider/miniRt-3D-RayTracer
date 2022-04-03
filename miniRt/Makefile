# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 18:14:03 by mel-amma          #+#    #+#              #
#    Updated: 2022/04/03 18:15:35 by mel-amma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = miniRt.c
NAME = miniRt
RM = rm -f
CFLAGS =  -g -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit -fsanitize=address


all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)


clean :
	$(RM) $(NAME) 
	
fclean : clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY : all clean fclean re
