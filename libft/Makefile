NAME := libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -fPIC

SRCS := ft_atoi.c \
        ft_bzero.c \
        ft_strdup.c \
        ft_substr.c \
        ft_calloc.c \
        ft_isalpha.c \
        ft_isalnum.c \
        ft_strjoin.c \
        ft_isascii.c \
        ft_isprint.c \
        ft_isdigit.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_memcpy.c \
        ft_memmove.c \
        ft_memset.c \
        ft_putendl_fd.c \
        ft_putstr_fd.c \
        ft_putchar_fd.c \
        ft_strchr.c \
        ft_strlcat.c \
        ft_striteri.c \
        ft_strlcpy.c \
        ft_strlen.c \
        ft_strncmp.c \
        ft_putnbr_fd.c \
        ft_split.c \
        ft_itoa.c \
        ft_strmapi.c \
        ft_strtrim.c \
        ft_strnstr.c \
        ft_strrchr.c \
        ft_tolower.c \
        ft_toupper.c

OBJS := $(SRCS:.c=.o)
DEPS := $(OBJS:.o=.d)

all: $(NAME)

# Regrouper les objets dans la bibliothèque statique.
$(NAME): $(OBJS)
	ar rcs $@ $^

# Compiler les sources et générer les dépendances.
%.o: %.c Makefile
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