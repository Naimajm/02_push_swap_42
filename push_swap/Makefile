
# ARCHIVO MAKEFILE PROYECTO 42 "PUSH_SWAP" --------------------------------

# VARIABLES -----------------------------------------
# ---------------------------------------------------

# NOMBRE SALIDA ARCHIVO BIBLIOTECA ".a"
NAME = push_swap.a

# nombre compilador
CC := cc

# flags de compilacion
CFLAGS := -Wall -Wextra -Werror

# COMPRESION A 1 ARCHIVO
MAKE_LIBRARY = ar -rcs

# SUBCARPETA PARTE OBLIGATORIA -> SRC
# SRC_DIR := push_swap

# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA
SRC := stack_init.c stack_utils.c \
free.c \
command_push.c command_rotate.c command_reverse_rotate.c command_swap.c \
sort_min.c \
push_swap_init.c push_swap_command.c \
split.c \

# libft.a

# LISTA ARCHIVOS .O SEGUN ARCHIVO C
OBJ_FILES := $(SRC:%.c=%.o)

# RECETAS -----------------------------------------
# ---------------------------------------------------.

# receta predeterminada
all: $(NAME)

# FUNCION PPAL -> CREACION ARCHIVO LIBRERIA ESTATICA .a
$(NAME): $(OBJ_FILES)
	$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 

# RECETA BORRAR ARCHIVOS '.o' -> '-f' ignora error si no encuentra archivos y elimina sin solicitar confirmacion
clean:
	rm -f $(OBJ_FILES)

# ejecuta clean + borrado archivo '.a'
fclean: clean
	rm -f $(NAME)

# FUNCION RECONSTRUCCION 
# -> ELIMINACION ARCHIVOS '.o' + archivos biblioteca '.a'
# NUEVA COMPILACION CON RECETA $(NAME)
re: fclean all

.PHONY: all clean fclean re

