CC = gcc
CFLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address
NAME = cub3D
LIBFT_DIR = libft
MLX_DIR = mlx
MLX = libmlx.dylib
INCLUDES = -I$(HEADERS_DIR)
HEADERS_LIST = libft.h
HEADERS_DIR = .
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
SRCS = main.c file_parameters.c map_parsing.c little_utils.c little_utils_2.c little_utils_3.c little_utils_4.c player.c run_engine.c render_frame.c draw.c engine_utils.c pixel.c sprite_init.c sprite_render.c sprite_utils.c create_bmp.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEP_DIR := $(OBJ_DIR)/.deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS)
POSTCOMPILE = mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

LDFLAGS = -L$(LIBFT_DIR) -L.   #search for library in ./ path
LDLIBS = -lft -lmlx  #link libft library

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
		@echo "$(YELLOW)'cub3d' Object files were born!$(DEF)"
		@$(MAKE) -C $(LIBFT_DIR)/
		@$(MAKE) -C $(MLX_DIR)/
		@cp $(MLX_DIR)/$(MLX) .
		@$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
		@echo "$(GREEN)Program '$@' is ready to be used.$(DEF)"

debug: $(NAME)
		@$(CC) $(LDFLAGS) $(LDLIBS) -o $(NAME) -gdwarf $(SRCS)
		@echo "$(WHITE)Debugging initiated.$(DEF)"

$(OBJ_DIR):
		@mkdir -p $@
		@echo "$(CYAN)Folder '$@' was created.$(DEF)"

$(OBJ_DIR)/%.o: %.c $(DEP_DIR)/%.d | $(DEP_DIR)
		@$(COMPILE.c) -c $< -o $@
		@$(POSTCOMPILE)
		@echo "$(RED).$(DEF)\c"

$(DEP_DIR):
		@mkdir -p $@
		@echo "$(CYAN)Folder "$@" was created.$(DEF)"

DEPFILES = $(SRCS:%.c=$(DEP_DIR)/%.d)
$(DEPFILES):

cleandep:
		@rm -rf $(DEP_DIR)

clean:
		@rm -rf $(OBJ_DIR)
		@$(MAKE) clean -C $(LIBFT_DIR)/
		@echo "$(RED)Folder '$(OBJ_DIR)' and all files inside were deleted.$(DEF)"

cleandebug:
		@rm -rf $(NAME).dSYM
		@echo "$(MAGENTA)Debug files were deleted.$(DEF)"

fclean: clean
		@rm -f $(NAME)
		@rm -f $(MLX)
		@echo "$(MAGENTA)Library '$(MLX)' was deleted.$(DEF)"
		@$(MAKE) fclean -C $(LIBFT_DIR)
		@$(MAKE) clean -C $(MLX_DIR)
		@rm -f cub3D.bmp
		@echo "$(MAGENTA)Program '$(NAME)' was deleted.$(DEF)"

re: fclean all

include $(wildcard $(DEPFILES))

.PHONY: all clean fclean re bonus cleandep debug
