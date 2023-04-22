# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 16:14:40 by svillalv          #+#    #+#              #
#    Updated: 2022/09/21 12:48:11 by svillalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar rcs
RM = rm -f
SRC	=	ft_print_hex.c ft_print_ptr.c ft_print_utils.c ft_printf.c \
		ft_print_unsigned.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strchr.c ft_tolower.c ft_toupper.c ft_strlcpy.c \
		ft_strlcat.c ft_strlen.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c
		
OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC)
	$(AR) $(NAME) $(OBJ)

bonus:
	$(CC) -c $(CFLAGS) $(SRC) $(SRC_BONUS)
	$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus
