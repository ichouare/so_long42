# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 11:19:00 by ichouare          #+#    #+#              #
#    Updated: 2022/12/23 18:17:10 by ichouare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = so_long2D

CC = cc

FLAGS = -Wall -Wextra -Werror 

FLAGS2 =  -lmlx -framework OpenGL -framework AppKit

SRC = srcs/main.c srcs/event.c srcs/ft_itoa.c srcs/get_next_line_utils.c \
 	srcs/get_next_line.c srcs/path.c srcs/textures.c srcs/draw.c srcs/extra_ft.c


OBJS = $(SRC:.c=.o)

HEADER = srcs/get_next_line.h

all: $(NAME)


$(NAME): $(OBJS) $(HEADER)
	$(CC)  $(FLAGS) $(FLAGS2) $(OBJS) -o $@
 
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all