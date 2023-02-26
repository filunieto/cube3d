#----------------------------- Makefile -----------------------------

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = inc
SRC = src
INCLUDES = 
SRCS = src/main.c
OBJS = $(SRCS:.c=.o)
NAME = cub3d

#------------------------ MLX_DEPENDENCIES --------------------------
DEPENDENCIES_LINUX = -MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX42 = ./MLX42
INC_MLX := $(MLX42)/include

#Variables to make an executable in differents OS
LINUX = Linux
MAC = 

all: $(NAME)

re: fclean
	$(MAKE) all

libmlx:
	cmake $(MLX42) -B $(MLX42)/build
	make -C $(MLX42)/build -j4

ifeq ($(shell uname -s), $(LINUX))

%.o: %.c $(INCLUDES) libmlx
	$(CC) $(CFLAGS) -I$(INC) -I$(INC_MLX) $(DEPENDENCIES_LINUX	) -c $(filter %.c, $<) -o $@

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(FLAGS) -o $@ $(OBJS)

else
	@echo "OS not ok"

endif


clean:
	rm -rf $(MLX42)/build
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean libmlx
