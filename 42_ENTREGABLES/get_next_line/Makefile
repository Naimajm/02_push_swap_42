
# ARCHIVO MAKEFILE BASICO PROYECTO 42 "GET_NEXT_LINE" --------------------------------

# VARIABLES -----------------------------------------
# ---------------------------------------------------

NAME = get_next_line.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE_LIBRARY = ar -rcs

SRC := get_next_line.c get_next_line_utils.c 

OBJ_FILES := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

