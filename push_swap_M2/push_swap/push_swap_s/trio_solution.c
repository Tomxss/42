/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trio_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:22:09 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:22:10 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** if 2 and 3 numbers
*/

int				duo(t_stack *stacks)
{
	sa(stacks);
	ft_putstr("sa\n");
	return (1);
}

static t_oper	*steps_for_trio(t_stack *stacks, t_oper *steps)
{
	set_stack_a_min_max(stacks);
	if (stacks->a_mxi == stacks->a_topi + 1 && stacks->a_mni == stacks->a_topi)
		steps = add_step(add_step(steps, 8), 0);
	else if (stacks->a_mxi == stacks->a_topi && stacks->a_mni == stacks->a_topi + 2)
		steps = add_step(add_step(steps, 5), 0);
	else if (stacks->a_mxi == stacks->a_topi && stacks->a_mni == stacks->a_topi + 1)
		steps = add_step(steps, 5);
	else if (stacks->a_mxi == stacks->a_topi + 2 && stacks->a_mni == stacks->a_topi + 1)
		steps = add_step(steps, 0);
	else if (stacks->a_mxi == stacks->a_topi + 1 && stacks->a_mni == stacks->a_topi + 2)
		steps = add_step(steps, 8);
	return (steps);
}

int				trio(t_stack *stacks, t_oper *steps_five, int scene)
{
	t_oper		*steps;

	steps = NULL;
	if (scene == 1)
	{
		steps = steps_for_trio(stacks, steps);
		exec_free(stacks, &steps);
	}
	else if (scene == 2)
	{
		(stacks->size == 4) ? (stacks->a_topi = 1) : (0);
		(stacks->size == 5) ? (stacks->a_topi = 2) : (0);
		(steps_five) ? (steps = steps_five) : (0);
		steps = steps_for_trio(stacks, steps);
		stacks->a_topi = 0;
		exec_free(stacks, &steps);
	}
	else if (scene == 3)
	{
		exec_free(stacks, &steps_five);
		steps = steps_for_trio(stacks, steps);
		exec_free(stacks, &steps);
	}
	return (1);
}
