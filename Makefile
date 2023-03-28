#----------------------------- Makefile -----------------------------

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = inc
SRC = src
INCLUDES = $(INC)/Screen.h $(INC)/shapes/Shapes.h $(INC)/player/Player.h \
		   $(INC)/game/Game.h $(INC)/map/Map.h 
SRCS = $(SRC)/main.c $(SRC)/Screen.c $(SRC)/shapes/Line.c \
	   $(SRC)/shapes/utilsLine.c $(SRC)/shapes/utilsPoint.c \
	   $(SRC)/shapes/Square.c $(SRC)/player/Player.c \
	   $(SRC)/player/Direction.c $(SRC)/game/Game.c \
	   $(SRC)/game/ResizeHook.c $(SRC)/game/KeyHook.c \
	   $(SRC)/player/ClearingImage.c $(SRC)/map/Map.c \
	   $(SRC)/map/UtilsMap.c $(SRC)/game/Paint.c $(SRC)/map/Movement.c \
	   $(SRC)/map/Utils_Draw_Map.c $(SRC)/map/Checking_Collisions_Sides.c \
	   $(SRC)/map/Utils_Collisions.c $(SRC)/shapes/Rotations.c \
	   $(SRC)/game/Utils_Minimap.c $(SRC)/game/Ray_Cast.c \
	   $(SRC)/game/MouseHook.c

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
