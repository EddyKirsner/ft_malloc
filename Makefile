ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINK = libft_malloc.so
SRC_DIR = src/
OBJ_DIR = obj/

CC = cc

CFLAGS = -Wall -Wextra -Werror -fPIC

FILES = malloc.c free.c realloc.c show_alloc_mem.c

SRCS = $(addprefix $(SRC_DIR), $(FILES))

OBJS = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

LIBFT = libft/libft.a

all:
	$(MAKE) -C libft
	$(MAKE) $(LINK)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -shared -o $@ $(OBJS) $(LIBFT) -pthread

$(LINK): $(NAME)
	ln -sfn $(NAME) $(LINK)

$(LIBFT):
	$(MAKE) -C libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(LINK)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re