NAME1 = checker
NAME2 = push_swap

OUT = ../

LIBFT = libft.a
LIBFT_F = /libft

CHECKER = $(NAME1)
PUSH_SWAP = $(NAME2)

SHARED_FILES = swap.c
SHARED_FILES += rotate.c
SHARED_FILES += rev_rotate.c
SHARED_OBJ = $(SHARED_FILES:.c=.o)

PUSH_FILES = push_swap.c
PUSH_FILES += error_handling.c
PUSH_FILES += extra.c
PUSH_FILES += solutions.c
PUSH_FILES += sorting_method.c
PUSH_FILES += stack_initial.c
PUSH_FILES += steps.c
PUSH_FILES += verbose_mode.c
PUSH_OBJ = $(PUSH_FILES:.c=.o)

CHK_FILES = checker.c
CHK_FILES += startup.c
CHK_FILES += print.c
CHK_FILES += action.c
CHK_FILES += history.c
CHK_OBJ = $(CHK_FILES:.c=.o)

all:
	@make -C $(LIBFT)

$(NAME1):
	echo "$(NAME1) compiling... \c"; \
	gcc -Wall -Wextra -Werror -c $(CHK_FILES); \
	gcc -Wall -Wextra -Werror $(CHK_OBJ) $(SHARED_OBJ) $(LIBFT_F)$(LIBFT) -o $(NAME1); \
	cp $(NAME1) $(OUT); \
	echo "$(NAME1) compiled"; \

$(NAME2):
	@echo "$(NAME)2 compiling... \c"; \
	@gcc -Wall -Wextra -Werror -c $(PUSH_FILES); \
	@gcc -Wall -Wextra -Werror $(PUSH_OBJ) $(SHARED_OBJ) $(LIBFT_F)$(LIBFT) -o $(NAME2); \
	@cp $(NAME2) $(OUT); \
	@echo "$(NAME) compiled"; \

.PHONY: clean

clean:
	@#echo "$(LIBFT) folder:\c"
	@make clean -C $(LIBFT)
	@rm -rf $(PUSH_OBJ) $(SHARED_OBJ) $(CHK_OBJ)| wc -l | tr '\n' ' ' && echo *.o files deleted

fclean: clean
	@#echo "$(LIBFT) folder:\c"
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME2) $(NAME1) | wc -l | tr '\n' ' ' && echo $(NAME2) and $(NAME1) deleted

re: fclean all
