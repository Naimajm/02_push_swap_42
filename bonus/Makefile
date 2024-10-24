
# ARCHIVO MAKEFILE BONUS PROYECTO 42 "PUSH_SWAP"  --------------------------------

# VARIABLES -----------------------------------------
# ---------------------------------------------------

# NOMBRE SALIDA ARCHIVO BIBLIOTECA ".a"
NAME = checker.a

# nombre compilador
CC := cc

# flags de compilacion
CFLAGS := -Wall -Wextra -Werror

# COMPRESION A 1 ARCHIVO
MAKE_LIBRARY = ar -rcs


PUSH_SWAP_ARCHIVE = ../push_swap/push_swap.a

# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA
SRC := 
#split.c stack_init.c stack_utils.c \

# LISTA ARCHIVOS .O SEGUN ARCHIVO C
OBJ_FILES := $(SRC:%.c=%.o)

# RECETAS -----------------------------------------
# ---------------------------------------------------.

# receta predeterminada
all: $(NAME)

# FUNCION PPAL -> CREACION ARCHIVO LIBRERIA "CHECKER" Y COPIA EN CARPETA 'push_swap'
$(NAME): $(OBJ_FILES) $(PUSH_SWAP_ARCHIVE)
	$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 
	cp $(NAME) ../push_swap 

# FUNCION OBLIGATORIA -> CREACION ARCHIVO LIBRERIA EN PARTE OBLIGATORIA
$(PUSH_SWAP_ARCHIVE) :
	cd ../push_swap && make

# RECETA BORRAR ARCHIVOS '.o' -> '-f' ignora error si no encuentra archivos y elimina sin solicitar confirmacion
clean:
	rm -f $(OBJ_FILES)

# ejecuta clean + borrado archivo '.a'
fclean: clean
	rm -f $(NAME)
	cd ../push_swap && rm -f $(NAME)

# FUNCION RECONSTRUCCION 
# -> ELIMINACION ARCHIVOS '.o' + archivos biblioteca '.a'
# NUEVA COMPILACION CON RECETA $(NAME)
re: fclean all

.PHONY: all clean fclean re