
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
NAME := push_swap
NAME_BONUS := checker

# VARIABLES -----------------------------------------
# ---------------------------------------------------

CC 		:= cc # nombre compilador
CFLAGS 	:= -Wall -Wextra -Werror # flags de compilacion

# COMPRESION A 1 ARCHIVO -> LIBRERIAS .a
MAKE_LIBRARY := ar -rcs  
# $(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 

# DIRECTORIOS -----------------------------------------
# ---------------------------------------------------

LIBFT_DIR	:= ./libft

# DIRECTORIOS BONUS -----------------------------------------
# ---------------------------------------------------

GET_NEXT_LINE_DIR 	:= ./get_next_line
BONUS_DIR := ./bonus

# ARCHIVOS LIBRERIAS -----------------------------------------
# ---------------------------------------------------

LIBFT_ARCHIVE 			:= ${LIBFT_DIR}/libft.a
GET_NEXT_LINE_ARCHIVE 	:= ${GET_NEXT_LINE_DIR}/get_next_line.a

# RECURSOS -----------------------------------------
# ---------------------------------------------------
# LISTADO ARCHIVOS A INCLUIR EN BIBLIOTECA

SRC := $(OBJS_DIR)/stack_init.c $(OBJS_DIR)/stack_utils.c $(OBJS_DIR)/split.c \
$(OBJS_DIR)/free.c $(OBJS_DIR)/sort.c \
$(OBJS_DIR)/command_push.c $(OBJS_DIR)/command_rotate.c $(OBJS_DIR)/command_reverse_rotate.c $(OBJS_DIR)/command_swap.c \
$(OBJS_DIR)/push_swap_init.c $(OBJS_DIR)/push_swap_command.c \

SRC_BONUS := checker.c \

# LISTA ARCHIVOS .O SEGUN ARCHIVO C
# OBJ_FILES 		:= $(SRC:${OBJ_DIR}/%.c=${OBJ_DIR}/%.o)
OBJ_FILES_BONUS := $(SRC_BONUS:%.c=%.o)

# OBJ_FILES		= $(patsubst ${OBJ_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})

OBJS_DIR		:= ./push_swap
OBJS_DIR_BONUS	:= ./bonus

# The %.o: %.c rule is used to compile the object files.
# $< is used to get the first dependency.
# $@ is used to get the target.
# -c flag is used to compile the source files.

#$(OBJS_DIR)

# COMPILACION -----------------------------------------
# ---------------------------------------------------

# The @ symbol is used to hide the command from the terminal.
# -o flag is used to specify the output file.	

# receta predeterminada 
all: $(NAME) # $(NAME_BONUS)

# FUNCION PPAL -> CREACION ARCHIVO LIBRERIA ESTATICA .a
$(NAME): ft_libft ft_get_next_line $(OBJ_FILES)
	@echo "$(ORANGE)📌​ Compiling $(NAME)... $(DEF_COLOR)"

	@make -C $(LIBFT_DIR)
	@make -C $(GET_NEXT_LINE_DIR)

	@${CC} ${CFLAGS} -o ${NAME} $(OBJS_DIR)/$(OBJ_FILES) $(LIBFT_ARCHIVE)	

	@echo "$(DARK_GREEN)$(NAME) has been created ✓$(DEF_COLOR)"

# CONVERSION ARCHIVOS TIPO .c en .o

# EJECUTA COMPILACION BONUS
bonus: $(NAME_BONUS)

${NAME_BONUS}: ftlibft ftprintf ${OBJ_FILES} ${OBJ_FILES_BONUS}
	@echo "$(ORANGE)📌​ Compiling Bonus 🠲 $(NAME_BONUS) $(DEF_COLOR)"
 
	@${CC} ${CFLAGS} -o ${NAME} $(OBJ_FILES) $(OBJ_FILES_BONUS) $(LIBFT_ARCHIVE) $(GET_NEXT_LINE_ARCHIVE)
			
	@echo "$(DARK_GREEN)$(NAME_BONUS) has been created ✓$(DEF_COLOR)"

# COMPILACION LIBRERIA LIBFT
ft_libft:
	@echo "$(ORANGE)📌​ Compiling Libft library... $(DEF_COLOR)"

	@cd ${LIBFT_DIR} && $(MAKE) all > /dev/null 2>&1

	@echo "$(DARK_GREEN) Libft library created ✓ $(DEF_COLOR)"

# COMPILACION LIBRERIA GET_NEXT_LINE
ft_get_next_line:
	@echo "$(ORANGE)📌​ Compiling Get_next_line library... $(DEF_COLOR)"

	@cd ${GET_NEXT_LINE_DIR} && $(MAKE) all > /dev/null 2>&1

	@echo "$(DARK_GREEN) Get_next_line library created ✓ $(DEF_COLOR)"

# RECETA BORRAR ARCHIVOS OBJETOS
# The clean rule is used to clean the object files.
clean:
	@echo "${ORANGE}🗑️​ Removing object files...${NAME}...${DEF_COLOR}"
	
	@rm -f $(OBJ_FILES)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(GET_NEXT_LINE_DIR)

	@echo "${DARK_GREEN}Cleaning objects ${NAME}...is done! ${DEF_COLOR}"

# ejecuta clean + borrado archivo '.a'
fclean: clean
	@echo "${ORANGE}🗑️ Removing files *.a...${NAME}... ${DEF_COLOR}"

	@rm -f push_swap/push_swap
#@rm -f $(OBJS_DIR_BONUS)/$(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(GET_NEXT_LINE_DIR)

	@echo "${DARK_GREEN}Cleaning ${NAME} is done! ${DEF_COLOR}"

# RECOMPILACION -----------------------------------------
# ---------------------------------------------------

# FUNCION RECONSTRUCCION 
# -> ELIMINACION ARCHIVOS '.o' + archivos biblioteca '.a'
# NUEVA COMPILACION CON RECETA $(NAME)
re: fclean all

.PHONY: all clean fclean re ft_libft ft_get_next_line bonus

