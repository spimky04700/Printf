# Nom de la bibliothèque
NAME = libftprintf.a

# Compilateur
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# Fichiers sources
SRC = ft_printf.c \
	handlers.c \
	numbers.c \
	utils.c \
	main.c

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Règle principale
all: $(NAME)

# Compilation de la lib
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compilation des .o
%.o: %.c $(INC_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

# Nettoyage des objets
clean:
	rm -f $(OBJ)

# Nettoyage complet
fclean: clean
	rm -f $(NAME) test_ftprintf

# Recompilation totale
re: fclean all

# Compilation de test
test: $(NAME)
	$(CC) $(CFLAGS) -I$(INC_DIR) main.c -L. -lftprintf -o test_ftprintf
	./test_ftprintf

.PHONY: all clean fclean re test
