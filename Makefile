# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconti <aconti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 15:10:20 by aconti            #+#    #+#              #
#    Updated: 2024/03/05 09:18:20 by aconti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
SRCS = bonus.c events.c init.c main.c math_utils.c other_utils.c render.c string_utils.c
OBJS = $(SRCS:.c=.o)
MLX = "https://github.com/42Paris/minilibx-linux.git"
MLX_DIR = minilibx-linux
FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext
COMPILE = gcc -Wall -Wextra -Werror -g

all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
	@git clone $(MLX)
	@cd $(MLX_DIR) && ./configure

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) $(FLAGS) -o $(NAME) -g

%.o: %.c
	cc -c $< -o $@

clean:
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(NAME) -d -R $(MLX_DIR)

re: fclean all