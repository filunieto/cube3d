#----------------------------- Makefile -----------------------------

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = inc
SRC = src
INCLUDES = $(INC)/Screen.h $(INC)/shapes/Shapes.h
SRCS = $(SRC)/main.c $(SRC)/Screen.c $(SRC)/shapes/Line.c \
	   $(SRC)/shapes/utilsLine.c 
OBJS = $(SRCS:.c=.o)
NAME = cub3d
GRAPHIC_LIBRARY = MLX42/build/libmlx42.a
#------------------------ MLX_DEPENDENCIES --------------------------
DEPENDENCIES_LINUX = $(GRAPHIC_LIBRARY) -ldl -lglfw -pthread -lm
DEPENDENCIES_MAC = MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit
MLX42 = ./MLX42
INC_MLX := $(MLX42)/include

#Variables to make an executable in differents OS
LINUX = Linux
MAC = Darwin

all: $(NAME)

re: fclean
	$(MAKE) all

$(GRAPHIC_LIBRARY):
	cmake $(MLX42) -B $(MLX42)/build
	make -C $(MLX42)/build -j4

ifeq ($(shell uname -s), $(LINUX))

%.o: %.c $(INCLUDES) $(GRAPHIC_LIBRARY)
	$(CC) $(CFLAGS) -I$(INC) -I$(INC_MLX) -c $(filter %.c, $<) -o $@

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(FLAGS) -o $@ $(OBJS) $(DEPENDENCIES_LINUX)

else ifeq ($(shell uname -s), $(MAC))
$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(@) $(OBJS) $(DEPENDENCIES_MAC) -lglfw -L"/Users/${USER}/.brew/opt/glfw/lib/"

%.o: %.c $(INCLUDES) $(GRAPHIC_LIBRARY)
	$(CC) $(CFLAGS) -I$(INC) -I$(INC_MLX) -c $(filter %.c, $<) -o $@

endif


clean:
	rm -rf $(MLX42)/build
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean libmlx
