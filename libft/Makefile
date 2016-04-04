NAME = libft.a

FLAGS = -Wall -Wextra -Werror

LDFLAGS = -I ./includes/

SRC = ft_adrtostr.c \
	  ft_atoi.c \
	  ft_bzero.c \
	  ft_createinttab.c \
	  ft_intlen.c \
	  ft_inttohexa.c \
	  ft_inttooctal.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isescaped.c \
	  ft_islower.c \
	  ft_isprint.c \
	  ft_isupper.c \
	  ft_itoa.c \
	  ft_litoa.c \
	  ft_longlen.c \
	  ft_lstadd.c \
	  ft_lstadd_end.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_mintomaj.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putlong.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putunsint.c \
	  ft_putwchar.c \
	  ft_putwstr.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strndup.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strredup.c \
	  ft_strrejoin.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_ulitoa.c \
	  ft_ulongtooctal.c \
	  ft_unsintlen.c \
	  ft_wcharlen.c \
	  ft_word_count.c \
	  ft_wstrlen.c \
	  ft_wstrndup.c \
	  ft_wstrnew.c


OBJ = $(SRC:.c=.o)
	SRC_PATH	= ./srcs/
	OBJ_PATH	= ./objs/
	SRCS		= $(addprefix $(SRC_PATH), $(SRC))
	OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Compilation of $(NAME) : DONE ! \n"

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mv $(OBJ) $(OBJ_PATH)

clean:
	@rm -f $(OBJS)
		@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re