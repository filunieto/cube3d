
RESET = \033[0m
GREEN_G = \033[1;32m
GREEN_F = \033[1;0m\033[32m
MAGEN_G = \033[1;36m
MAGEN__F = \033[1;0m\033[36m
RED_G = \033[1;31m
RED_F = \033[1;0m\033[31m


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

# poner aqui lo necesario 

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rdf $(OBJS);

fclean : 
	rm -rdf $(NAME)

re : fclean all

run : all
	./$(NAME) map.cub

test1: all
	@echo "$(MAGEN_G)📝 test 1 con un archivo como input$(MAGEN_F) $(RESET)"
	./$(NAME) map.cub

test2: all
	@echo "$(MAGEN_G)📝 test 2 with no input y tiene que dar error$(MAGEN_F) $(RESET)"
	./$(NAME)


