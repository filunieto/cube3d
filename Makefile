NAME = cub3d
INC = inc
SRC = src

SRCS = 	src/main.c 				\
		src/parse/parse.c 		\
		src/error/error.c		\

INCLUDES = 	$(INC)/Screen.h  	\
			inc/parse/Parse.h 	\
			inc/headers.h		\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror



all : $(NAME)
	

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rdf $(OBJS);

fclean : 
	rm -rdf $(NAME)

re : fclean all

run : re
	./$(NAME)