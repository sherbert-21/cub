# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 19:44:28 by sherbert          #+#    #+#              #
#    Updated: 2022/06/06 14:15:10 by sherbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS	= -c -Wall -Werror -Wextra 

HEAD = libft.h

SRC = \
ft_atoi.c \
ft_save_free.c \
ft_isascii.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isprint.c \
ft_tolower.c \
ft_toupper.c \
ft_strlen.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strchr.c \
ft_strrchr.c \
ft_strnstr.c \
ft_strncmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_bzero.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_calloc.c \
ft_strdup.c \
ft_itoa.c \
ft_strjoin.c \
ft_substr.c \
ft_strtrim.c \
ft_split.c \
ft_strmapi.c \
ft_putstr_fd.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstadd_front.c \
ft_lstnew.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
ft_check.c \
gnl.c \
utils_gnl.c \
ft_printf.c \
ft_treatment.c \
ft_treat_width.c \
ft_u_itoa.c \
ft_ull_base.c \
ft_putchar.c \
ft_str_tolower.c \
ft_putstrprec.c \
ft_treat_string.c \
ft_treat_char.c \
ft_treat_pointer.c \
ft_treat_int.c \
ft_treat_uint.c \
ft_treat_percent.c \
ft_treat_hexa.c \
ft_treat_flags.c \
abs.c \
ft_rgb.c \


OBJ		= 	$(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	gcc  $(FLAGS) $(SRC) 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
