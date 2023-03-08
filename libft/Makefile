# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 21:41:57 by anramire          #+#    #+#              #
#    Updated: 2022/04/29 00:20:25 by anramire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------- Makefile ------------------------------

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
INCLUDE = libft.h

OBJS = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
	   ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o\
	   ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o\
	   ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o\
	   ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o\
	   ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o\
	   ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o

BONUSOBJS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o\
		   	ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o\
		   	ft_lstiter.o ft_lstmap.o

%.o: %.c
	gcc $(CFLAGS) -c $^

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	ar rcs $(NAME) $(OBJS)

re: fclean all

bonus: $(BONUSOBJS) $(OBJS) $(INCLUDE)
	ar rcs $(NAME) $(BONUSOBJS) $(OBJS)
