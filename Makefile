NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

LDFLAGS = -I ./includes/

SRC = main.c \
	  ft_check.c \
	  ft_create.c \
	  ft_display.c \
	  ft_free.c \
	  ft_get.c \
	  ft_get2.c \
	  ft_get_files.c \
	  ft_get_dir.c \
	  ft_padding.c \
	  ft_print_details.c \
	  ft_print_solo.c \
	  ft_sort.c \
	  ft_sort_dir.c \
	  ft_swap.c

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