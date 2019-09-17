/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:13:45 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:13:50 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void		ft_use_commands(int n, t_stack *stacks)
{
	void		(*oper[11])(t_stack*);

	oper[1] = &sa;
	oper[2] = &sb;
	oper[3] = &ss;
	oper[4] = &pa;
	oper[5] = &pb;
	oper[6] = &ra;
	oper[7] = &rb;
	oper[8] = &rr;
	oper[9] = &rra;
	oper[0] = &rrb;
	oper[10] = &rrr;
	oper[n](stacks);
}

static	int		ft_game_act_2(t_history *history, int oper, t_stack *stacks)
{
	if (oper == 15)
		ft_print_history(history, 1);
	if (oper == 16)
		ft_print_history(history, 0);
	if (oper == 17)
		return (1);
	if (oper == 18)
	{
		if (stacks->clear == 0)
			stacks->clear = 1;
		else if (stacks->clear == 1)
			stacks->clear = 0;
	}
	return (0);
}

int				ft_game_act(char *argument, t_stack *stacks, t_history *history)
{
	int			oper;

	oper = ft_check_game_command(argument);
	free(argument);
	if (oper >= 0 && oper < 11)
		ft_use_commands(oper, stacks);
	else if (oper == 11)
		return (-1);
	else if (oper == 12)
		ft_print_list_of_commands();
	else if (oper == 13)
	{
		if (stacks->a_amt_of_elems < stacks->size)
			ft_printf("warning: stack not filled\n"
		"only %d of %d numbers in the stack a\n", stacks->a_amt_of_elems, stacks->size);
		if (is_stack_in_order(stacks) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else if (oper == 14)
		activate_verbose(stacks);
	else
		return (ft_game_act_2(history, oper, stacks));
	return (0);
}
