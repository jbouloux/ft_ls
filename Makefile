NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

LDFLAGS = -I ./includes/

SRC = main.c \
	  ft_ls_tools.c \
	  ft_ls_tools2.c \
	  ft_ls_tools3.c \
	  ft_getdir_r.c \
	  ft_get_files.c \
	  ft_display.c \
	  ft_display2.c \
	  ft_display3.c \
	  ft_detail.c \
	  ft_sort.c

OBJ = $(SRC:.c=.o)
	SRC_PATH	= ./srcs/
	OBJ_PATH	= ./objs/
	SRCS		= $(addprefix $(SRC_PATH), $(SRC))
	OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

make:
	make -C libft/

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) -L libft/ -lft -g
	@echo "Compilation of $(NAME) : DONE ! \n"

$(OBJS): $(SRCS)
	make -C libft/
	gcc -I libft/includes/ $(FLAGS) -c $^ -g
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mv $(OBJ) $(OBJ_PATH)

clean:
	make -C libft/ clean
	@rm -f $(OBJS)
		@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re