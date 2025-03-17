NAME = push_swap
SRCS_DIR = srcs/
OBJS_DIR = objs/
SRCS = $(SRCS_DIR)push_swap.c $(SRCS_DIR)push.c $(SRCS_DIR)swap.c $(SRCS_DIR)rotate.c $(SRCS_DIR)rev_rotate.c $(SRCS_DIR)stack_utils.c $(SRCS_DIR)sort_three.c $(SRCS_DIR)stack_init.c $(SRCS_DIR)errors.c $(SRCS_DIR)init_a_to_b.c $(SRCS_DIR)init_b_to_a.c $(SRCS_DIR)sort_stacks.c 
OBJS = $(patsubst $(SRCS_DIR)%.c,$(OBJS_DIR)%.o,$(SRCS))
LIBFT = Libft/libft.a
FT_PRINTF = ft_Printf/libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra -g
AR = ar rcs
RM = rm -rf


all: $(NAME)


$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	make -C $(dir $(LIBFT))

$(FT_PRINTF):
	make -C $(dir $(FT_PRINTF))

clean:
	$(RM) $(OBJS_DIR)
	make -C Libft clean
	make -C ft_Printf clean

fclean: clean
	$(RM) $(NAME)
	make -C Libft fclean
	make -C ft_Printf fclean

re: fclean all

.PHONY: all clean fclean re
