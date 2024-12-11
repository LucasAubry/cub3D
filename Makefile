#-----------------------Flags_and_Name---------------------
NAME	=	cub3D
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude -Ilib/inc -IMLX42/include -g
CREAD	=	-lreadline -lncursesw
LIB			=	lib
SRCDIR	=	src
INCDIR	=	include
LIBFT		=	$(LIB)/libft.a
MLX			=	MLX42
LIBMLX 	=	$(MLX)/build/libmlx42.a
LIBS = $(LIBFT) $(LIBMLX) -lglfw -pthread -lm

#------------------------Source-----------------------------

# Sources and objects
FILESEXEC = main init line_drawing raycasting render texture move minimap door knife init_player free\

SRCS = $(addprefix src/exec/, $(addsuffix .c, $(FILESEXEC)))
OBJS = $(addprefix obj/exec/, $(addsuffix .o, $(FILESEXEC)))

#------------------------Colors-----------------------------

define generate_random_color
python3 -c "import random; \
print(''.join(['\033[38;5;' + str(random.randint(16, 255)) + 'm' + c + '\033[0m' for c in '$(1)']))"
endef

#------------------------Rules------------------------------
#VALGRIND_SUPP = valgrind.supp

all: $(LIBFT) $(LIBMLX) $(NAME)

obj:
	mkdir -p obj/exec

$(LIBFT):
	@$(MAKE) --quiet -C $(LIB)
	@echo "Libft compilée."

$(LIBMLX):
	@if [ ! -d "$(MLX)" ]; then \
		echo "Clonage de MLX42 library..."; \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX); \
	fi
	@echo "Compilation de MLX42 library..."
	@cmake -S $(MLX) -B $(MLX)/build
	@cmake --build $(MLX)/build

.c.o:
	$(CC) $(CFLAGS) -c $< -o $<:.c=.o) $(CREAD) $(LIBS)

$(NAME): obj ${OBJS}
	@$(call generate_random_color, $(CC) $(CFLAGS) -o $@ $(OBJS))
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(CREAD) $(LIBS)

obj/%.o: src/%.c
	@$(call generate_random_color, $(CC) $(CFLAGS) -c $< -o $@)
	@$(CC) $(CFLAGS) -c $< -o $@

valgrind: $(NAME)
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes --track-fds=yes --trace-children=yes --suppressions=mlx42.supp ./$(NAME)

clean:
	@$(MAKE) --quiet -C $(LIB) clean
	rm -f ${OBJS}

fclean: clean
	@$(MAKE) --quiet -C $(LIB) fclean
	rm -f ${NAME}
	rm -rf obj
	rm -rf $(MLX)/build

re: fclean all

norminette:
	@echo "Norminette de $(NAME) dans $(SRCDIR) et $(INCDIR)..."
	@if norminette $(SRCDIR)/*.c $(INCDIR)/*.h | grep -v "OK!" | grep -q "Error!"; then \
		norminette $(SRCDIR)/*.c $(INCDIR)/*.h | grep -v "OK!" | \
		while read line; do \
			if echo $$line | grep -q "Error!"; then \
				echo "\033[0;31m$$line\033[0m"; \
			else \
				echo "$$line"; \
			fi; \
		done; \
	else \
		echo "\033[0;32mAll files are norminette friendly !\033[0m"; \
	fi

.PHONY: all clean fclean re valgrind
