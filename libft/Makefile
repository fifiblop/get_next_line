# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 15:22:44 by pdelefos          #+#    #+#              #
#    Updated: 2016/01/29 11:24:28 by pdelefos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c \
			ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
			ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
			ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
			ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
			ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
			ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
			ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
			ft_strnstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
			ft_strstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
			ft_lstiter.c ft_lstmap.c ft_abs.c ft_strupcase.c ft_strlowcase.c \
			ft_lstsize.c ft_lst_pback.c ft_itoa_base.c

OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror $(HEADER)

LIB_NAME = libft.a

INC = ./includes/

HEADER = -I $(INC)

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ_NAME)
	$(CC) $(CFLAGS) -c $(SRC_NAME)
	ar rc $(LIB_NAME) $(OBJ_NAME)
	ranlib $(LIB_NAME)

clean : 
	rm -fv $(OBJ_NAME)

fclean : clean
	rm -fv $(NAME)

re : fclean all

norme :
	norminette $(SRC_NAME)
	norminette $(INC)libft.h

.PHONY : all clean fclean re norme
