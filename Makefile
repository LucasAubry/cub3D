#-----------------------Flags_and_Name---------------------
NAME	=	cub3D
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude -g
CREAD	=	-lreadline -lncursesw
LIBS	=	-Llib -lmlx_Linux -lXext -lX11 -lm

#------------------------Source-----------------------------

# Sources and objects
FILES = main \

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix obj/, $(addsuffix .o, $(FILES)))

#------------------------Colors-----------------------------

define generate_random_color
python3 -c "import random; \
print(''.join(['\033[38;5;' + str(random.randint(16, 255)) + 'm' + c + '\033[0m' for c in '$(1)']))"
endef

#------------------------Rules------------------------------
#VALGRIND_SUPP = valgrind.supp

all:	${NAME}

obj:
	mkdir -p obj

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(CREAD) $(LIBS)

$(NAME): obj ${OBJS}
		@$(call generate_random_color, $(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS))
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(CREAD) $(LIBS)


obj/%.o: src/%.c
	@$(call generate_random_color, $(CC) $(CFLAGS) -c $< -o $@)
	@$(CC) $(CFLAGS) -c $< -o $@

valgrind: $(NAME)
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes --track-fds=yes --trace-children=yes --suppressions=$(VALGRIND_SUPP) ./$(NAME)

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}
		rm -rf obj

re:	fclean all

.PHONY: all clean fclean re


