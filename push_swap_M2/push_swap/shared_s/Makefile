# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/23 11:27:57 by tcoetzee          #+#    #+#              #
#    Updated: 2019/08/23 11:27:58 by tcoetzee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re silent_clean silent_fclean silent_re

NAME = slib.a
RM = /bin/rm -rfv
RMS = /bin/rm -rf
CFILES = error_handling.c extra_1.c initial_stack.c swap.c
CFILES += rotate.c rev_rotate.c verbose_mode.c
CFILES += commands.c extra_2.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): 
	@echo "$(NAME) compiling... \c"
	@gcc -Wall -Wextra -Werror -c $(CFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "$(NAME) created"
	
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

