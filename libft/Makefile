# Library name
LIB = libft.a

# Compiler and flags
CC = cc
FLAGS = -Wall -Werror_text -Wextra

# Source files (libft and ft_printf)
SRC = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
      ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
      ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
      ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
      ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
      ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
      ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
      get_next_line.c get_next_line_utils.c chars.c extras.c  ft_printf.c \
      numbers.c

# Source files in ft_printf folder (using wildcard)


# Bonus files
BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
        ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

# Object files
OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

# Default target: Build the library
all: $(LIB)

# Rule to build the library from object files
$(LIB): $(OBJS)
	ar -rcs $(LIB) $(OBJS)

# Rule to compile .c to .o
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Rule for bonus target
bonus: $(BONUS_OBJS)
	ar -rcs $(LIB) $(BONUS_OBJS)

# Clean object files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Clean object files and the library
fclean: clean
	rm -f $(LIB)

# Rebuild everything
re: fclean all

# Declare 'all', 'bonus', 'clean', 'fclean', and 're' as phony targets
.PHONY: all bonus clean fclean re
