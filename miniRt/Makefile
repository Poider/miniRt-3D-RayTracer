# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 18:14:03 by mel-amma          #+#    #+#              #
#    Updated: 2022/04/24 14:38:26 by klaarous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
SRC = miniRt.c helpers.c split.c \
		camera.c color.c intersections.c light.c material.c math_utils.c matrices.c\
		object.c precomputed.c ray.c shading.c sphere.c transformation_matrices.c\
		tuples.c world.c
NAME = miniRt
LIBRARIES = ../libmlx_Linux.a -lX11 -lXext
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
