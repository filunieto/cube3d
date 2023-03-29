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
CFLAGS = -Wall -Werror -Wextra -g
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
		$(SRC)/parse/parse.c 				\
		$(SRC)/parse/parse_tools.c 			\
		$(SRC)/error/error.c				\
		$(SRC)/gnl/get_next_line.c			\
		$(SRC)/gnl/get_next_line_utils.c	\
		$(SRC)/parse/read_map.c			\
		$(SRC)/parse/check_lines.c			\
		$(SRC)/parse/check_rgb.c			\
		$(SRC)/parse/check_map.c			\
		$(SRC)/parse/map_consistence.c		\
		$(SRC)/parse/map_one_player.c		\
		$(SRC)/parse/normalice_map.c		\
		$(SRC)/parse/init_parse.c			\
	   $(SRC)/map/UtilsMap.c $(SRC)/game/Paint.c $(SRC)/map/Movement.c \
	   $(SRC)/map/Utils_Draw_Map.c $(SRC)/map/Checking_Collisions_Sides.c \
	   $(SRC)/map/Utils_Collisions.c $(SRC)/shapes/Rotations.c \
	   $(SRC)/game/Utils_Minimap.c $(SRC)/game/Ray_Cast.c \
	   $(SRC)/game/MouseHook.c $(SRC)/map/Utils_Draw_Map2.c \
	   $(SRC)/map/Collisions.c $(SRC)/game/Utils_Ray_Cast.c \
	   $(SRC)/game/Utils_Paint.c


OBJS = $(SRCS:.c=.o)
NAME = cub3d
VALGRIND = val
GRAPHIC_LIBRARY = MLX42/build/libmlx42.a
LIBFT = ./libft/libft.a
MEMORY_LEAKS = ./memory-leaks/memory_leaks.a
MEMORY_LEAKS_INC = ./memory-leaks/include
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

$(MEMORY_LEAKS):
		make -C ./memory-leaks
ifeq ($(shell uname -s), $(LINUX))

%.o: %.c $(INCLUDES)  $(LIBFT)
	$(CC) $(CFLAGS) -g -I$(INC) -I$(INC_MLX) -I$(MEMORY_LEAKS_INC) -I./libft -c $(filter %.c, $<) -o $@

$(NAME): $(OBJS) $(INCLUDES) $(GRAPHIC_LIBRARY) $(MEMORY_LEAKS)
	$(CC) $(FLAGS) -g -o $@ $(OBJS) ./libft/libft.a $(DEPENDENCIES_LINUX) $(MEMORY_LEAKS)
else ifeq ($(shell uname -s), $(MAC))


$(NAME): $(OBJS) $(INCLUDES) $(GRAPHIC_LIBRARY) $(LIBFT) $(MEMORY_LEAKS)
	$(CC) $(CFLAGS) $(MEMORY_LEAKS) ./libft/libft.a -g -o $(@) $(OBJS) $(DEPENDENCIES_MAC) -lglfw -L"/Users/${USER}/.brew/opt/glfw/lib/"

%.o: %.c $(INCLUDES) $(GRAPHIC_LIBRARY)
	$(CC) $(CFLAGS) -g -I$(INC) -I$(INC_MLX) -I$(MEMORY_LEAKS_INC) -c $(filter %.c, $<) -o $@

endif

clean:
	rm -rf $(MLX42)/build
	rm -rf $(OBJS)
	make -C ./libft clean
	make -C ./memory-leaks clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean
	make -C ./memory-leaks fclean

$(VALGRIND): $(NAME)
	valgrind --leak-check=full ./$(NAME)
	rm -rf $(NAME).dSYM
.PHONY: all re clean fclean val


# Felipe rules

run :
	./$(NAME)

test1: all
	@echo "$(MAGEN_G)📝 test error 1. Extension incorrecta $(MAGEN_F) $(RESET)"
	./$(NAME) ./src/scenarios/example.pipin

test2: all
	@echo "$(MAGEN_G)📝 test error 2. incorrect configuration input file $(MAGEN_F) $(RESET)"
	./$(NAME) ./src/scenarios/error.cub

test3: all
	@echo "$(MAGEN_G)📝 test 3 $(MAGEN_F) $(RESET)" 
	./$(NAME) ./src/scenarios/escenario1.cub

test4: all
	@echo "$(MAGEN_G)📝 test 4 $(MAGEN_F) $(RESET)"
	./$(NAME) ./src/scenarios/cubed.cub

test5: all
	@echo "$(MAGEN_G)📝 test 5 $(MAGEN_F) $(RESET)"
	./$(NAME) ./src/scenarios/cubedwrong.cub




