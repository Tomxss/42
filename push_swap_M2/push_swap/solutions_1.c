/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:21:06 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 16:24:21 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			down_b_helper(t_stack *stacks, int index)
{
	return (stacks->size - index);
}

int			return_up_a(t_stack *stacks, int index)
{
	int			num;

	if (index == stacks->a_top)
		return (0);
	num = stacks->a_top - index;
	if (num < 0)
		num = -1 * num;
	return (num);
}

int			return_down_a(t_stack *stacks, int index)
{
	if (index == stacks->size - 1 && stacks->a_amt_of_elems == 1)
		return (0);
	return (stacks->size - index);
}

t_oper		*to_b_up(int up_a)
{
	t_oper			*steps;

	steps = NULL;
	while (up_a > 0)
	{
		steps = add_step(steps, 5);
		up_a--;
	}
	steps = add_step(steps, 4);
	return (steps);
}

t_oper		*to_b_down(int dw_a)
{
	t_oper			*steps;

	steps = NULL;
	while (dw_a > 0)
	{
		steps = add_step(steps, 8);
		dw_a--;
	}
	steps = add_step(steps, 4);
	return (steps);
}
