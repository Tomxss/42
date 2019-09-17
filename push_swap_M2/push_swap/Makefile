# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 14:46:18 by tcoetzee          #+#    #+#              #
#    Updated: 2019/09/16 14:51:31 by tcoetzee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

LIBFT = libft.a
LIBFT_F = ./libft/

CHECKER = $(NAME1)
PUSH_SWAP = $(NAME2)

SHARED_FILES = swap.c
SHARED_FILES += rotate.c
SHARED_FILES += rev_rotate.c
SHARED_OBJ = $(SHARED_FILES:.c=.o)

PUSH_FILES = push_swap.c
PUSH_FILES += error_handling.c
PUSH_FILES += extra_1.c
PUSH_FILES += extra_2.c
PUSH_FILES += solutions_1.c
PUSH_FILES += solutions_2.c
PUSH_FILES += sorting_method_1.c
PUSH_FILES += sorting_method_2.c
PUSH_FILES += sorting_method_3.c
PUSH_FILES += sorting_method_4.c
PUSH_FILES += stack_initial.c
PUSH_FILES += stack_staging.c
PUSH_FILES += steps_1.c
PUSH_FILES += steps_2.c
PUSH_FILES += steps_3.c
PUSH_FILES += verbose_mode.c
PUSH_FILES += flags.c
PUSH_OBJ = $(PUSH_FILES:.c=.o)

all: $(NAME2)
	make -C $(LIBFT_F)
$(NAME2):
	echo "$(NAME2) compiling... \c"; \
	gcc -Wall -Wextra -Werror -c $(PUSH_FILES) $(SHARED_FILES); \
	gcc -Wall -Wextra -Werror $(PUSH_OBJ) $(SHARED_OBJ) $(LIBFT_F)$(LIBFT) -o $(NAME2); \
	echo "$(NAME) compiled"; \

.PHONY: clean

clean:
	@#echo "$(LIBFT) folder:\c"
	@make clean -C $(LIBFT_F)
	@rm -rf $(PUSH_OBJ) $(SHARED_OBJ) | wc -l | tr '\n' ' ' && echo *.o files deleted

fclean: clean
	@#echo "$(LIBFT) folder:\c"
	@make fclean -C $(LIBFT_F)
	@rm -rf $(NAME2) | wc -l | tr '\n' ' ' && echo $(NAME2) deleted

re: fclean all
