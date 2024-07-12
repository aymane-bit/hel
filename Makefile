NAME = push_swap

LIBFT_DIR = LIBFT

LIBFT = libft.a

LIBFT_OUTPUT = $(LIBFT_DIR)/$(LIBFT)

FILES = array_creator.c \
		big_sort.c \
		five_sort.c \
		four_sort.c \
		ft_rra.c \
		ft_sa.c \
		push_swap.c \
		sort_start.c \
		three_sort.c \
		utils.c \

OFILS = $(FILES:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILS) $(LIBFT)
	$(CC) $(FLAGS) $(OFILS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	mv $(LIBFT_OUTPUT) .

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OFILS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all
