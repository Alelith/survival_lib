NAME = survivalib.a

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_DIR = src/
OBJ_DIR = obj/

AR = ar rcs
CC = cc -Wall -Wextra -Werror -g

INCLUDE = -I include

CHECK_DIR = check/
CHECK_FILES = is_alphabetic is_alphanumeric is_ascii is_digit is_print str_compare

CONVERSION_DIR = conversion/
CONVERSION_FILES = int_to_str str_to_int to_lower to_upper

MEMORY_DIR = memory/
MEMORY_FILES = callocation mem_compare mem_copy mem_move mem_search mem_set set_zero

STRING_DIR = string/
STRING_FILES = str_concat str_copy str_duplicate str_join str_len \
				str_search_char str_search_rev_char str_search_str str_split str_substring str_trim

PRINTF_DIR = printf/
PRINTF_FILES = print_format \
	internal/print/print_nbr \
	internal/print/print_str

SRC_FILES += $(addprefix $(CHECK_DIR), $(CHECK_FILES))
SRC_FILES += $(addprefix $(CONVERSION_DIR), $(CONVERSION_FILES))
SRC_FILES += $(addprefix $(MEMORY_DIR), $(MEMORY_FILES))
SRC_FILES += $(addprefix $(STRING_DIR), $(STRING_FILES))
SRC_FILES += $(addprefix $(PRINTF_DIR), $(PRINTF_FILES))

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJSF = .cache_exists

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "$(GREEN)Library created: $@$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJSF)
	@echo "$(CYAN)Compiling: $<$(DEF_COLOR)"
	@$(CC) -c $< -o $@ $(INCLUDE)
	

$(OBJSF):
	@echo "$(MAGENTA)Creating dirs$(DEF_COLOR)"
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(CHECK_DIR)
	@mkdir -p $(OBJ_DIR)$(CONVERSION_DIR)
	@mkdir -p $(OBJ_DIR)$(MEMORY_DIR)
	@mkdir -p $(OBJ_DIR)$(STRING_DIR)
	@mkdir -p $(OBJ_DIR)$(PRINTF_DIR)
	@mkdir -p $(OBJ_DIR)$(PRINTF_DIR)internal/

clean:
	@echo "$(RED)Cleaning lib files$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

.PHONY: all clean
