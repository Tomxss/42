/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:04:05 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 17:05:19 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		a_placement(t_stack *stacks)
{
	int			index;
	int			elem;

	index = stacks->a_mni;
	elem = 4;
	if (stacks->stack_b[stacks->b_top] < stacks->a_min)
		return (stacks->a_mni);
	else if (stacks->stack_b[stacks->b_top] > stacks->a_max)
		return (stacks->a_mni);
	while ((index < stacks->size))
	{
		if (stacks->stack_b[stacks->b_top] < stacks->stack_a[index++])
			return (--index);
		elem--;
	}
	if (elem > 1)
	{
		index = stacks->a_top;
		while (index != stacks->a_mni)
			if (stacks->stack_b[stacks->b_top] < stacks->stack_a[index++])
				return (--index);
	}
	return (0);
}

void			clean_a(t_stack *stacks)
{
	t_oper *steps;

	steps = NULL;
	set_a_min_max(stacks);
	if (stacks->a_mxi == stacks->a_top)
		steps = add_step(NULL, 5);
	if (stacks->a_amt_of_elems == 4)
	{
		if (stacks->a_mxi == stacks->a_top + 1)
			steps = add_step(add_step(NULL, 8), 8);
		else if (stacks->a_mxi == stacks->a_top + 2)
			steps = add_step(NULL, 8);
	}
	else
	{
		if (stacks->a_mxi == stacks->a_top + 1)
			steps = add_step(add_step(NULL, 5), 5);
		else if (stacks->a_mxi == stacks->a_top + 2)
			steps = add_step(add_step(NULL, 8), 8);
		else if (stacks->a_mxi == stacks->a_top + 3)
			steps = add_step(NULL, 8);
	}
	exec_free(stacks, &steps);
}

t_oper			*bravo(t_oper *steps, t_stack *stacks)
{
	int	place;

	place = a_placement(stacks);
	if (place == stacks->a_top)
		;
	else if (place == stacks->a_top + 1)
		steps = add_step(steps, 5);
	else if (place == stacks->a_top + 2)
		steps = add_step(add_step(steps, 5), 5);
	else if (place == stacks->a_top + 3)
		steps = add_step(steps, 8);
	return (add_step(steps, 3));
}

t_oper			*alpha(t_oper *steps, t_stack *stacks)
{
	set_a_min_max(stacks);
	if (stacks->stack_b[stacks->b_top] < stacks->a_min)
		steps = add_step(steps, 3);
	else if (stacks->stack_b[stacks->b_top] > stacks->a_max)
		steps = add_step(steps, 3);
	else if (stacks->stack_b[stacks->b_top] < \
			stacks->stack_a[stacks->a_top + 1])
		steps = add_step(add_step(steps, 5), 3);
	else if (stacks->stack_b[stacks->b_top] > \
			stacks->stack_a[stacks->a_top + 1])
		steps = add_step(add_step(steps, 8), 3);
	return (steps);
}
