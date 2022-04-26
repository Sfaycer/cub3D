CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a
INCLUDES = -I$(HEADERS_DIR)
HEADERS_LIST = libft.h
HEADERS_DIR = .
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
SRCS = ft_printf.c ft_printf_putchar.c ft_printf_conversion.c ft_printf_conversion_char.c ft_printf_conversion_string.c ft_printf_putstr.c ft_printf_conversion_decimal.c ft_printf_conversion_unsigned.c ft_printf_conversion_hex.c ft_printf_conversion_pointer.c ft_printf_width.c ft_printf_precision.c ft_printf_precision_numbers.c ft_printf_output.c ft_printf_flags.c ft_printf_conversion_n.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEP_DIR := $(OBJ_DIR)/.deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS)
POSTCOMPILE = mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

LDFLAGS = -L.   #search for library in ./ path
LDLIBS = -lftprintf   #link libft library

DEF = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
LYELLOW = \033[0;33m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

all:
		@$(MAKE) $(NAME)

$(NAME): $(OBJS)
		@echo "$(YELLOW)'Printf' Object files were born!$(DEF)"
		@ar -rc $@ $?
		@ranlib $@
		@echo "$(GREEN)Library '$@' has been created.$(DEF)"

$(OBJ_DIR):
		@mkdir -p $@
		@echo "$(CYAN)Folder '$@' was created.$(DEF)"

$(OBJ_DIR)/%.o: %.c $(DEP_DIR)/%.d | $(DEP_DIR)
		@$(COMPILE.c) -c $< -o $@
		@$(POSTCOMPILE)
		@echo "$(LYELLOW).$(DEF)\c"

$(DEP_DIR):
		@mkdir -p $@
		@echo "$(CYAN)Folder "obj" was created.$(DEF)"

DEPFILES = $(SRCS:%.c=$(DEP_DIR)/%.d)
$(DEPFILES):

cleandep:
		@rm -rf $(DEP_DIR)

clean:
		@rm -rf $(OBJ_DIR)
		@echo "$(RED)Folder '$(OBJ_DIR)' and all files inside were deleted.$(DEF)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(MAGENTA)Library '$(NAME)' was deleted.$(DEF)"

re: fclean all

include $(wildcard $(DEPFILES))

.PHONY: all clean fclean re bonus cleandep
