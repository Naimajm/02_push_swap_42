
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
LIBRARY := push_swap.a
NAME := push_swap

CC := cc # nombre compilador
CFLAGS := -Wall -Wextra -Werror # flags de compilacion
MAKE_LIBRARY := ar -rcs # COMPRESION A 1 ARCHIVO -> LIBRERIAS .a
#$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 

# DIRECTORIOS -----------------------------------------
# ---------------------------------------------------
LIBFT_DIR := ../libft

# ARCHIVOS LIBRERIAS -----------------------------------------
# ---------------------------------------------------
LIBFT_ARCHIVE := libft.a

# RECURSOS -----------------------------------------
# ---------------------------------------------------
# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA
SRC := split.c stack_init.c stack_utils.c \
free.c sort.c \
command_push.c command_rotate.c command_reverse_rotate.c command_swap.c \
push_swap_init.c push_swap_command.c \
main.c \

OBJ_FILES := $(SRC:%.c=%.o) # LISTA ARCHIVOS .O SEGUN ARCHIVO C

# RECETAS -----------------------------------------
# ---------------------------------------------------.
 
all: $(NAME) # receta predeterminada

# $< is used to get the first dependency.
# $@ is used to get the target.
# -c flag is used to compile the source files.

# FUNCION PPAL -> CREACION ARCHIVO COMPILADO
#$(NAME): $(OBJ_FILES) $(LIBFT_DIR)/$(LIBFT_ARCHIVE)
$(NAME): $(LIBRARY) $(LIBFT_DIR)/$(LIBFT_ARCHIVE)
	@echo "$(ORANGE)📌​ Compiling $(NAME)... $(DEF_COLOR)"
	$(CC) ${CFLAGS} $^ -o $(NAME)
##$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 
	@echo "$(DARK_GREEN)$(NAME) has been created ✓$(DEF_COLOR)"

# FUNCION SECUNDARIA -> LIBRERIA 'push_swap.a' para exe 'push_swap' y 'checker' bonus
$(LIBRARY) : $(OBJ_FILES) 
	$(MAKE_LIBRARY) $(LIBRARY) $^ 

# FUNCION LIBRERIA LIBFT -> CREACION ARCHIVO LIBRERIA
$(LIBFT_ARCHIVE) :
	@echo "$(ORANGE)📌​ Compiling $(LIBFT_ARCHIVE) library... $(DEF_COLOR)"
	cd ${LIBFT_DIR} && make
	@echo "$(DARK_GREEN) $(LIBFT_ARCHIVE) library created ✓ $(DEF_COLOR)"

# RECETA BORRAR ARCHIVOS
clean:
	@echo "${ORANGE}🗑️​ Removing object files...${NAME}...${DEF_COLOR}"
	rm -f $(OBJ_FILES)
	@echo "${DARK_GREEN}Cleaning objects ${NAME}...is done! ${DEF_COLOR}"


fclean: clean # ejecuta clean + borrado archivo '.a'
	@echo "${ORANGE}🗑️ Removing files...${NAME}... ${DEF_COLOR}"
	rm -f $(NAME)
	@echo "${DARK_GREEN}Cleaning ${NAME} is done! ${DEF_COLOR}"

# RECOMPILACION -----------------------------------------
# ---------------------------------------------------
# FUNCION RECONSTRUCCION -> ELIMINACION ARCHIVOS '.o' + archivos biblioteca '.a'
# NUEVA COMPILACION CON RECETA $(NAME)
re: fclean all
	@echo "${DARK_GREEN}🗑️ Cleaning ${NAME} is done and 📌 $(NAME) has been created✓! ${DEF_COLOR}"

.PHONY: all clean fclean re

