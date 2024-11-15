
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

NAME = checker

CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE_LIBRARY = ar -rcs

LIBFT_DIR	:= ../libft
PUSH_SWAP_DIR := ..
GET_NEXT_LINE_DIR := ../get_next_line

LIBFT_ARCHIVE := libft.a
PUSH_SWAP_ARCHIVE := push_swap.a
GET_NEXT_LINE_ARCHIVE := get_next_line.a

SRC := checker_bonus.c \

OBJ_FILES := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):  $(OBJ_FILES) $(LIBFT_ARCHIVE) $(PUSH_SWAP_ARCHIVE) $(GET_NEXT_LINE_ARCHIVE)
	@echo "$(ORANGE)📌​ Compiling $(NAME)... $(DEF_COLOR)"

	$(CC) ${CFLAGS} $(OBJ_FILES) $(PUSH_SWAP_DIR)/$(PUSH_SWAP_ARCHIVE) $(LIBFT_DIR)/$(LIBFT_ARCHIVE)  $(GET_NEXT_LINE_DIR)/$(GET_NEXT_LINE_ARCHIVE) -o $(NAME)
	cp $(NAME) $(PUSH_SWAP_DIR)/ 

	@echo "$(DARK_GREEN)$(NAME) has been created ✓$(DEF_COLOR)"

$(LIBFT_ARCHIVE) :
	@echo "$(ORANGE)📌​ Compiling $(LIBFT_ARCHIVE) library... $(DEF_COLOR)"
	cd $(LIBFT_DIR) && make
	@echo "$(DARK_GREEN) $(LIBFT_ARCHIVE) library created ✓ $(DEF_COLOR)"

$(PUSH_SWAP_ARCHIVE) :
	@echo "$(ORANGE)📌​ Compiling $(PUSH_SWAP_ARCHIVE) library... $(DEF_COLOR)"
	cd $(PUSH_SWAP_DIR) && make
	@echo "$(DARK_GREEN) $(PUSH_SWAP_ARCHIVE) library created ✓ $(DEF_COLOR)"

$(GET_NEXT_LINE_ARCHIVE) :
	@echo "$(ORANGE)📌​ Compiling $(GET_NEXT_LINE_ARCHIVE) library... $(DEF_COLOR)"
	cd $(GET_NEXT_LINE_DIR) && make
	@echo "$(DARK_GREEN) $(GET_NEXT_LINE_ARCHIVE) library created ✓ $(DEF_COLOR)"

clean:
	@echo "${ORANGE}🗑️​ Removing object files...${NAME}...${DEF_COLOR}"
	rm -f $(OBJ_FILES)
	@echo "${DARK_GREEN}Cleaning objects ${NAME}...is done! ${DEF_COLOR}"

fclean: clean
	@echo "${ORANGE}🗑️ Removing files...${NAME}... ${DEF_COLOR}"
	rm -f $(NAME)
	cd $(PUSH_SWAP_DIR) && rm -f $(NAME)
	@echo "${DARK_GREEN}Cleaning ${NAME} is done! ${DEF_COLOR}"

re: fclean all
	make clean
	@echo "${DARK_GREEN}🗑️ Cleaning ${NAME} is done and 📌 $(NAME) has been created✓! ${DEF_COLOR}"

.PHONY: all clean fclean re