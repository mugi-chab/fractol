# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 15:14:13 by svillalv          #+#    #+#              #
#    Updated: 2023/04/21 17:53:23 by svillalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
SRCS	=	src/main.c src/check_args.c src/utils.c src/fractals.c src/hooks.c
CC		=	gcc
CFLAGS	=	-Wextra -Wall -Werror
RM		=	rm -rf
LIBFT	=	./Libs/libft
MLX42	=	./Libs/MLX42
HEADERS	=	-I include -I $(MLX42)/include/MLX42
LIBS	=	-lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(MLX42)/libmlx42.a $(LIBFT)/libft.a
OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			@make -C $(MLX42)
			@make -C $(LIBFT) --silent
			$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

clean:
			@make -C $(MLX42) cleans
			@make -C $(LIBFT) fclean --silent
			$(RM) $(OBJS)

fclean:		
		@make -C $(MLX42) clean
		@make -C $(LIBFT) fclean --silent
		$(RM) $(OBJS) $(NAME)

re:		fclean all

run:	all
		./$(NAME)

.PHONY:	all clean fclean re