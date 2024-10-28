
# ARCHIVO MAKEFILE BONUS PROYECTO 42 "PUSH_SWAP"  --------------------------------

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

# VARIABLES -----------------------------------------
# ---------------------------------------------------

# NOMBRE SALIDA ARCHIVO COMPILADO
NAME = checker

CC := cc # nombre compilador
CFLAGS := -Wall -Wextra -Werror # flags de compilacion
MAKE_LIBRARY = ar -rcs # COMPRESION A 1 ARCHIVO -> LIBRERIAS .a

# DIRECTORIOS -----------------------------------------
# ---------------------------------------------------
LIBFT_DIR	:= ../libft
PUSH_SWAP_DIR := ../push_swap
GET_NEXT_LINE_DIR := ../get_next_line

# ARCHIVOS LIBRERIAS -----------------------------------------
# ---------------------------------------------------
LIBFT_ARCHIVE := libft.a
PUSH_SWAP_ARCHIVE := push_swap.a
GET_NEXT_LINE_ARCHIVE := get_next_line.a

# RECURSOS -----------------------------------------
# ---------------------------------------------------
# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA
SRC := checker.c \

OBJ_FILES := $(SRC:%.c=%.o) # LISTA ARCHIVOS .O SEGUN ARCHIVO C

# RECETAS -----------------------------------------
# ---------------------------------------------------.

all: $(NAME) # receta predeterminada

# $< is used to get the first dependency.
# $@ is used to get the target.
# -c flag is used to compile the source files.

# FUNCION PPAL -> CREACION ARCHIVO COMPILACION "CHECKER" Y COPIA EN CARPETA 'push_swap'
$(NAME): $(OBJ_FILES) $(GET_NEXT_LINE_DIR)/$(GET_NEXT_LINE_ARCHIVE) $(PUSH_SWAP_DIR)/$(PUSH_SWAP_ARCHIVE) $(LIBFT_DIR)/$(LIBFT_ARCHIVE)
	@echo "$(ORANGE)📌​ Compiling $(NAME)... $(DEF_COLOR)"

	$(CC) ${CFLAGS} $^ -o $(NAME)
	cp $(NAME) ../push_swap 

	@echo "$(DARK_GREEN)$(NAME) has been created ✓$(DEF_COLOR)"

# FUNCION LIBRERIA LIBFT -> CREACION ARCHIVO LIBRERIA
$(LIBFT_ARCHIVE) :
	@echo "$(ORANGE)📌​ Compiling $(LIBFT_ARCHIVE) library... $(DEF_COLOR)"
	cd $(LIBFT_DIR) && make
	@echo "$(DARK_GREEN) $(LIBFT_ARCHIVE) library created ✓ $(DEF_COLOR)"

# FUNCION LIBRERIA PUSH_SWAP -> CREACION ARCHIVO LIBRERIA
$(PUSH_SWAP_ARCHIVE) :
	@echo "$(ORANGE)📌​ Compiling $(PUSH_SWAP_ARCHIVE) library... $(DEF_COLOR)"
	cd $(PUSH_SWAP_DIR) && make
	@echo "$(DARK_GREEN) $(PUSH_SWAP_ARCHIVE) library created ✓ $(DEF_COLOR)"

# FUNCION LIBRERIA GET_NEXT_LINE -> BONUS
$(GET_NEXT_LINE_ARCHIVE) :
	@echo "$(ORANGE)📌​ Compiling $(GET_NEXT_LINE_ARCHIVE) library... $(DEF_COLOR)"
	cd $(GET_NEXT_LINE_DIR) && make
	@echo "$(DARK_GREEN) $(GET_NEXT_LINE_ARCHIVE)line library created ✓ $(DEF_COLOR)"

# RECETA BORRAR ARCHIVOS '.o' -> '-f' ignora error si no encuentra archivos y elimina sin solicitar confirmacion
clean:
	@echo "${ORANGE}🗑️​ Removing object files...${NAME}...${DEF_COLOR}"
	rm -f $(OBJ_FILES)
	@echo "${DARK_GREEN}Cleaning objects ${NAME}...is done! ${DEF_COLOR}"

# ejecuta clean + borrado archivo '.a'
fclean: clean
	@echo "${ORANGE}🗑️ Removing files...${NAME}... ${DEF_COLOR}"
	rm -f $(NAME)
	cd $(PUSH_SWAP_DIR) && rm -f $(NAME)
	@echo "${DARK_GREEN}Cleaning ${NAME} is done! ${DEF_COLOR}"

# RECOMPILACION -----------------------------------------
# ---------------------------------------------------
# FUNCION RECONSTRUCCION -> ELIMINACION ARCHIVOS '.o' + archivos biblioteca '.a'
# NUEVA COMPILACION CON RECETA $(NAME)
re: fclean all
	@echo "${DARK_GREEN}🗑️ Cleaning ${NAME} is done and 📌 $(NAME) has been created✓! ${DEF_COLOR}"

.PHONY: all clean fclean re