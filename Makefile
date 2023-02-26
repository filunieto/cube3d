#----------------------------- Makefile -----------------------------

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = inc
SRC = src
INCLUDES = 
SRCS = src/main.c
OBJS = $(SRCS:.c=.o)
NAME = cub3d
LINUX = Linux

all: $(NAME)

re: fclean
	$(MAKE) all

ifeq ($(shell uname -s), $(LINUX))

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -I$(INC) -c $(filter %.c, $<) -o $@

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(FLAGS) -o $@ $(OBJS)

else
	@echo "OS not ok"

endif


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean
