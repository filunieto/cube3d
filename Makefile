
RESET = \033[0m
GREEN_G = \033[1;32m
GREEN_F = \033[1;0m\033[32m
MAGEN_G = \033[1;35m
MAGEN__F = \033[1;0m\035[36m
RED_G = \033[1;31m
RED_F = \033[1;0m\033[31m

VPATH	= src
INCFLAGS = -I libft -I include
LIBS	= libft/libft.a

HEADER	= 	inc/headers.h

NAME = cub3d
INC = inc
SRC = src

SRCS = 	src/main.c 						\
		src/parse/parse.c 				\
		src/parse/parse_tools.c 		\
		src/error/error.c				\
		src/gnl/get_next_line.c			\
		src/gnl/get_next_line_utils.c	\

OBJ		= $(addprefix obj/,$(notdir $(SRCS:.c=.o)))

INCLUDES = 	inc/Screen.h  		\
			inc/parse/Parse.h 		\
			inc/headers.h			\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror



all : $(NAME)

# poner aqui lo necesario 

# $(NAME) : $(OBJ) | $(LIBS)
# 	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft
# 	@echo "cube3d is compiled"

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

obj/%.o : %.c $(LIBS) $(HEADER) | obj
	$(CC) $(FLAGS) $(INCFLAGS) -c $< -o $@

obj :
	mkdir obj


$(LIBS) :
	-(cd libft && make)
	-(cd libft && make clean)

clean :
	rm -rdf obj

fclean : 
	rm -rdf $(NAME)

re : fclean all

run : all
	./$(NAME) src/scenarios/map1.cub

test1: all
	@echo "$(MAGEN_G)📝 test 1 con un archivo como input$(MAGEN_F) $(RESET)"
	./$(NAME) map.cub

test3: all
	@echo "$(MAGEN_G)📝 test 2 antonio$(MAGEN_F) $(RESET)"
	./$(NAME) antonio.cu


SRCS = 	$(SRC)/main.c 						\
		$(SRC)/parse/parse.c 				\
		$(SRC)/parse/parse_tools.c 		\
		$(SRC)/error/error.c				\
		$(SRC)/gnl/get_next_line.c			\
		$(SRC)/gnl/get_next_line_utils.c	\