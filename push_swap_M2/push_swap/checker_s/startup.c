/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:15:13 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:15:17 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static char		*ft_game_read(void)
{
	char		*argument;
	char		buf[2];

	buf[0] = '\0';
	buf[1] = '\0';
	argument = NULL;
	if (read(0, buf, 1) == -1)
		return (NULL);
	buf[1] = '\0';
	argument = ft_strnew(2);
	ft_memcpy(argument, buf, 1);
	argument[1] = '\0';
	return (argument);
}

static void		ft_play_again(t_stack *stacks, t_stack **stacks_copy,
								int **a_copy, int code)
{
	int			index;
	int			flags[2];

	if (code == 0)
	{
		*a_copy = (int*)malloc(sizeof(int) * stacks->size);
		index = -1;
		while (++index < stacks->size)
			(*a_copy)[index] = stacks->stack_a[index];
	}
	else if (code == 1)
	{
		flags[0] = 1;
		flags[1] = 1;
		*stacks_copy = initialize_stack(*a_copy, stacks->size, flags);
		ft_game_mode(*stacks_copy);
		free((*stacks_copy)->stack_a);
		free((*stacks_copy)->stack_b);
		free(*stacks_copy);
	}
	else
		free(*a_copy);
}

static void		ft_first_launch(t_stack *stacks, t_history **history)
{
	ft_printf("NEW GAME started\n");
	ft_print_list_of_commands();
	activate_verbose(stacks);
	*history = NULL;
}

void			ft_game_mode(t_stack *stacks)
{
	char		*argument;
	t_history	*history;
	int			code;
	int			*a_copy;
	t_stack		*stacks_copy;

	code = 0;
	ft_play_again(stacks, &stacks_copy, &a_copy, code);
	ft_first_launch(stacks, &history);
	while (1)
	{
		if ((argument = ft_game_read()) == NULL)
			break ;
		if (*argument == '\n')
		{
			free(argument);
			continue ;
		}
		history = ft_add_history(&history, argument);
		if ((code = ft_game_act(argument, stacks, history)) == -1 || code == 1)
			break ;
	}
	ft_clean_the_game_history(&history);
	ft_printf("GAME END\n");
	ft_play_again(stacks, &stacks_copy, &a_copy, code);
}
