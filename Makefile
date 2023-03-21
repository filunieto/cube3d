#----------------------------- Makefile -----------------------------

#------------------------ Colors --------------------------
RESET = \033[0m
GREEN_G = \033[1;32m
GREEN_F = \033[1;0m\033[32m
MAGEN_G = \033[1;36m
MAGEN__F = \033[1;0m\033[36m
RED_G = \033[1;31m
RED_F = \033[1;0m\033[31m


CC = gcc
CFLAGS = -Wall -Werror -Wextra  -O0 -g
INC = inc
SRC = src
INCLUDES = $(INC)/Screen.h $(INC)/shapes/Shapes.h $(INC)/player/Player.h \
		   $(INC)/game/Game.h $(INC)/map/Map.h \
			inc/Screen.h  			\
			inc/parse/Parse.h 		\


SRCS = $(SRC)/main.c $(SRC)/Screen.c $(SRC)/shapes/Line.c \
	   $(SRC)/shapes/utilsLine.c $(SRC)/shapes/utilsPoint.c \
	   $(SRC)/shapes/Square.c $(SRC)/player/Player.c \
	   $(SRC)/player/Direction.c $(SRC)/game/Game.c \
	   $(SRC)/game/ResizeHook.c $(SRC)/game/KeyHook.c \
	   $(SRC)/player/ClearingImage.c $(SRC)/map/Map.c \
	   $(SRC)/map/UtilsMap.c $(SRC)/game/Paint.c \
		src/parse/parse.c 				\
		src/parse/parse_tools.c 		\
		src/error/error.c				\
		src/gnl/get_next_line.c			\
		src/gnl/get_next_line_utils.c	\
		src/parse/read_map.c			\
		src/parse/check_lines.c			\
		src/parse/check_rgb.c			\
		src/parse/check_map.c			\
		src/parse/map_consistence.c		\
		src/parse/map_one_player.c		\

OBJS = $(SRCS:.c=.o)
NAME = cub3d
VALGRIND = val
GRAPHIC_LIBRARY = MLX42/build/libmlx42.a
LIBFT = ./libft/libft.a

#------------------------ MLX_DEPENDENCIES --------------------------
DEPENDENCIES_LINUX = $(GRAPHIC_LIBRARY) -ldl -lglfw -pthread -lm
DEPENDENCIES_MAC = MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit
MLX42 = ./MLX42
INC_MLX := $(MLX42)/include

#Variables to make an executable in differents OS
LINUX = Linux
MAC = Darwin

#------------------------- Recipes -----------------------

all: $(NAME)

re: fclean
	$(MAKE) all

$(LIBFT):
	make -C ./libft

$(GRAPHIC_LIBRARY):
	cmake $(MLX42) -B $(MLX42)/build
	make -C $(MLX42)/build -j4

ifeq ($(shell uname -s), $(LINUX))

%.o: %.c $(INCLUDES)  $(LIBFT)
	$(CC) $(CFLAGS) -g -I$(INC) -I$(INC_MLX) -I./libft -c $(filter %.c, $<) -o $@

$(NAME): $(OBJS) $(INCLUDES) $(GRAPHIC_LIBRARY)
	$(CC) $(FLAGS) -g -o $@ $(OBJS) ./libft/libft.a $(DEPENDENCIES_LINUX)

else ifeq ($(shell uname -s), $(MAC))

$(NAME): $(OBJS) $(INCLUDES) $(GRAPHIC_LIBRARY) $(LIBFT)
	$(CC) $(CFLAGS) ./memory-leaks/memory_leaks.a ./libft/libft.a -g -o $(@) $(OBJS) $(DEPENDENCIES_MAC) -lglfw -L"/Users/${USER}/.brew/opt/glfw/lib/"

%.o: %.c $(INCLUDES) $(GRAPHIC_LIBRARY) 
	$(CC) $(CFLAGS) -g -I$(INC) -I$(INC_MLX) -I./memory-leaks/include -c $(filter %.c, $<) -o $@

endif

clean:
	rm -rf $(MLX42)/build
	rm -rf $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

$(VALGRIND): $(NAME)
	valgrind --leak-check=full ./$(NAME)
	rm -rf $(NAME).dSYM
.PHONY: all re clean fclean val


# Felipe rules

run :
	./$(NAME)

test1: all
	@echo "$(MAGEN_G)📝 test 1 con un archivo como input$(MAGEN_F) $(RESET)"
	./$(NAME) ./src/scenarios/map1.cub

test2: all
	@echo "$(MAGEN_G)📝 test 2 $(MAGEN_F) $(RESET)"
	./$(NAME) ./src/scenarios/map_completo.cub

test3: all
	@echo "$(MAGEN_G)📝 test 3 para verificar parsing $(MAGEN_F) $(RESET)"
	./$(NAME) ./src/scenarios/parsing_test.cub

test4: all
	@echo "$(MAGEN_G)📝 test 4 para verificar coordenadas $(MAGEN_F) $(RESET)"
	./$(NAME) ./src/scenarios/coordenadas_linea.cub



leaks : all
	valgrind --leak-check=full ./$(NAME) ./src/scenarios/map_completo.cub