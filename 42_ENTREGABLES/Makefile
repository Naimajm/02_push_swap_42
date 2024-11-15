
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

LIBRARY := push_swap.a
NAME := push_swap 

CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE_LIBRARY := ar -rcs

LIBFT_DIR := ./libft
LIBFT_ARCHIVE := libft.a

NAME_BONUS = checker
BONUS_DIR := ./bonus

SRC := init_split.c init_stack.c init_stack_utils.c \
command_push.c command_rotate.c command_reverse_rotate.c command_swap.c \
sort.c sort_node_init.c sort_node_move.c \
main_push_swap.c main.c \

OBJ_FILES := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT_ARCHIVE) $(LIBRARY)
	@echo "$(ORANGE)📌​ Compiling $(NAME)... $(DEF_COLOR)"
	$(CC) ${CFLAGS} $(LIBRARY) $(LIBFT_DIR)/$(LIBFT_ARCHIVE) -o $(NAME)
	@echo "$(DARK_GREEN)$(NAME) has been created ✓$(DEF_COLOR)"

$(LIBRARY) : $(OBJ_FILES)
	@echo "$(ORANGE)📌​ Compiling $(LIBRARY)... $(DEF_COLOR)"
	$(MAKE_LIBRARY) $(LIBRARY) $^
	@echo "$(DARK_GREEN) $(LIBRARY) library created ✓ $(DEF_COLOR)"

$(LIBFT_ARCHIVE):
	@echo "$(ORANGE)📌​ Compiling $(LIBFT_ARCHIVE) library... $(DEF_COLOR)"
	cd ${LIBFT_DIR} && make
	@echo "$(DARK_GREEN) $(LIBFT_ARCHIVE) library created ✓ $(DEF_COLOR)"

## BONUS ---------------------------------------------------------

bonus: $(NAME_BONUS)

$(NAME_BONUS): 
	@echo "$(ORANGE)📌​ Compiling $(NAME_BONUS)... $(DEF_COLOR)"
	cd $(BONUS_DIR) && make
	@echo "$(DARK_GREEN)$(NAME_BONUS) has been created ✓$(DEF_COLOR)"

clean:
	@echo "${ORANGE}🗑️​ Removing object files...${NAME}...${DEF_COLOR}"
	rm -f $(OBJ_FILES)
	@echo "${DARK_GREEN}Cleaning objects ${NAME}...is done! ${DEF_COLOR}"

fclean: clean
	@echo "${ORANGE}🗑️ Removing files...${NAME} and $(LIBRARY)... ${DEF_COLOR}"
	rm -f $(NAME)
	rm -f $(LIBRARY)
	@echo "${DARK_GREEN}Cleaning ${NAME} is done! ${DEF_COLOR}"

re: fclean all 
	make clean
	@echo "${DARK_GREEN}🗑️ Cleaning $(NAME) is done and 📌 $(NAME) has been created✓! ${DEF_COLOR}"	

.PHONY: all clean fclean re

