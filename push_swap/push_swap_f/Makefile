.PHONY: all clean fclean re silent_clean silent_fclean silent_re

NAME = push_swap
RM = /bin/rm -rfv
RMS = /bin/rm -rf
SHARED_F = ../shared/
SLIB = slib.a
LIBFT_F = ../libft/
LIBFT = libft.a
OUT = ../
CFILES = push_swap.c
CFILES += push_algorithm.c
CFILES += push_if_3_numbers.c
CFILES += push_if_5_numbers.c
CFILES += push_steps_manipulations.c
CFILES += push_main_functions.c
CFILES += push_index_checker.c
CFILES += push_alternative_checker.c
CFILES += push_a_stack_rotation.c
CFILES += push_b_stack_up_rotation.c
CFILES += push_b_stack_down_rotation.c
CFILES += push_final_a_rotation.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@if [ ! -e $(SHARED_F)$(SLIB) ]; then \
		make silent_re -C $(SHARED_F); \
	fi
	@if [ ! -e $(LIBFT_F)$(LIBFT) ]; then \
		make silent_re -C $(LIBFT_F); \
	fi
	@if [ -e $(SHARED_F)$(SLIB) -a -e $(LIBFT_F)$(LIBFT) ]; then \
		echo "$(NAME) compiling... \c"; \
		gcc -Wall -Wextra -Werror -c $(CFILES); \
		gcc -Wall -Wextra -Werror $(OFILES) $(SHARED_F)$(SLIB) $(LIBFT_F)$(LIBFT) -o $(NAME); \
		cp $(NAME) $(OUT); \
		echo "$(NAME) compiled"; \
	else \
		echo "something wrong with $(LIBFT) or/and $(SLIB) libraries"; \
	fi

clean:
	@$(RM) $(OFILES) | wc -l | tr '\n' ' ' && echo ft_*.o files deleted

fclean: clean
	@$(RM) $(NAME) | wc -l | tr '\n' ' ' && echo $(NAME) deleted

re: fclean all

silent_clean:
	@$(RMS) $(OFILES)

silent_fclean: silent_clean
	@$(RMS) $(NAME)

silent_re: silent_fclean all