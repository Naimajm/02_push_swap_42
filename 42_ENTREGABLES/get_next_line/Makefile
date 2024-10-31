
# ARCHIVO MAKEFILE BASICO PROYECTO 42 "GET_NEXT_LINE" --------------------------------

# VARIABLES -----------------------------------------
# ---------------------------------------------------

# NOMBRE SALIDA ARCHIVO BIBLIOTECA ".a"
NAME = get_next_line.a

# nombre compilador
CC := cc

# flags de compilacion
CFLAGS := -Wall -Wextra -Werror

# COMPRESION A 1 ARCHIVO
MAKE_LIBRARY = ar -rcs

# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA
SRC := get_next_line.c get_next_line_utils.c 

# LISTA ARCHIVOS .O SEGUN ARCHIVO C
OBJ_FILES := $(SRC:%.c=%.o)

# RECETAS -----------------------------------------
# ---------------------------------------------------.

# receta predeterminada
all: $(NAME)

# FUNCION PPAL -> CREACION ARCHIVO LIBRERIA ESTATICA .a
$(NAME): $(OBJ_FILES)
	$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 

# RECETA BORRAR ARCHIVOS 
# '-f' ignora error si no encuentra archivos y elimina sin solicitar confirmacion
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

