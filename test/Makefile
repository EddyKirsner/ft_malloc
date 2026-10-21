NAME = test
CC = cc
CFLAGS = #-Wall -Wextra -Werror
CPPFLAGS = -I../src -I../libft

SRCS = test.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

LIB = ../libft_malloc.so ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re