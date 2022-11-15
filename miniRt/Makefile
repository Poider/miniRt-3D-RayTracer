# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 18:14:03 by mel-amma          #+#    #+#              #
#    Updated: 2022/11/15 17:14:52 by mel-amma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
SRC = miniRt.c helpers.c split.c \
		camera.c color.c intersections.c light.c material.c math_utils.c matrices.c free_ressources.c\
		object.c precomputed.c ray.c shading.c sphere.c cylinder.c cone.c cone1.c transformation_matrices.c\
		cylinder1.c intersections_helper.c light_helper.c light_helper1.c  math_utils1.c matrices_utils.c  \
		matrices_utils1.c matrices_utils2.c matrices_utils3.c object_init_shapes.c  object_utils.c pattern_utils.c \
		precomputed_utils.c transformation_matrices1.c tuples_utils.c tuples_utils1.c \
		tuples.c world.c plane.c pattern.c\
		./parsing/parse.c  ./parsing/init_attr_shapes.c ./parsing/make_shapes.c ./parsing/set_transformations.c \
		./parsing/settings.c ./parsing/settings_utils.c ./parsing/settings_utils1.c ./parsing/settings_utils2.c ./parsing/settings_utils3.c \
		./gnl/get_next_line.c ./gnl/get_next_line_utils.c  \
		draw_utils.c handle_error.c cube.c
NAME = miniRt
LIBRARIES = ../libmlx_Linux.a -lX11 -lXext
RM = rm -f
CFLAGS =  -g -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit -fsanitize=address


all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)


clean :
	$(RM) *.o
	
fclean : clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY : all clean fclean re
