
# ARCHIVO MAKEFILE BASICO + BONUS PROYECTO 42 "PUSH_SWAP" -----------------------

# INTERFAZ GRAFICA -----------------------------------------
# ---------------------------------------------------
DEL_LINE            = \033[2K
ITALIC              = \033[3m
BOLD                = \033[1m
DEF_COLOR           = \033[0;39m
GRAY                = \033[0;90m
RED                 = \033[0;91m
GREEN               = \033[0;92m
YELLOW              = \033[0;93m
BLUE                = \033[0;94m
MAGENTA             = \033[0;95m
CYAN                = \033[0;96m
WHITE               = \033[0;97m
BLACK               = \033[0;99m
ORANGE              = \033[38;5;209m
BROWN               = \033[38;2;184;143;29m
DARK_GRAY           = \033[38;5;234m
MID_GRAY            = \033[38;5;245m
DARK_GREEN          = \033[38;2;75;179;82m
DARK_YELLOW         = \033[38;5;143m

# NOMBRES -----------------------------------------
# ---------------------------------------------------

# NOMBRE SALIDA ARCHIVO COMPILADO
NAME = push_swap

# nombre compilador
CC := cc

# flags de compilacion
CFLAGS := -Wall -Wextra -Werror

# COMPRESION A 1 ARCHIVO
MAKE_LIBRARY = ar -rcs

# DIRECTORIOS -----------------------------------------
# ---------------------------------------------------

LIBFT_DIR := ../libft

# ARCHIVOS LIBRERIAS -----------------------------------------
# ---------------------------------------------------

LIBFT_ARCHIVE := ${LIBFT_DIR}/libft.a

# RECURSOS -----------------------------------------
# ---------------------------------------------------
# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA

SRC := split.c stack_init.c stack_utils.c \
free.c sort.c \
command_push.c command_rotate.c command_reverse_rotate.c command_swap.c \
push_swap_init.c push_swap_command.c \

# LISTA ARCHIVOS .O SEGUN ARCHIVO C
OBJ_FILES := $(SRC:%.c=%.o)

# RECETAS -----------------------------------------
# ---------------------------------------------------.

# receta predeterminada
all: $(NAME)

# FUNCION PPAL -> CREACION ARCHIVO LIBRERIA ESTATICA .a
$(NAME): ftlibft $(OBJ_FILES)
	@echo "$(ORANGE)📌​ Compiling $(NAME)... $(DEF_COLOR)"
	$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 
	@echo "$(DARK_GREEN) $(NAME) all created ✓$(DEF_COLOR)"

# COMPILACION LIBRERIA LIBFT
ftlibft:
	@cd ${LIBFT_DIR} && $(MAKE) all > /dev/null 2>&1

# RECETA BORRAR ARCHIVOS
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

