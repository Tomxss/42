/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quintet_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:30:07 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/20 12:30:23 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void			sort_a(t_stack *stacks)
{
	t_oper *steps;

	steps = NULL;
	set_stack_a_min_max(stacks);
	if (stacks->a_mxi == stacks->a_topi)
		steps = add_step(NULL, 5);
	if (stacks->a_amt_of_elems == 4)
	{
		if (stacks->a_mxi == stacks->a_topi + 1)
			steps = add_step(add_step(NULL, 8), 8);
		else if (stacks->a_mxi == stacks->a_topi + 2)
			steps = add_step(NULL, 8);
	}
	else
	{
		if (stacks->a_mxi == stacks->a_topi + 1)
			steps = add_step(add_step(NULL, 5), 5);
		else if (stacks->a_mxi == stacks->a_topi + 2)
			steps = add_step(add_step(NULL, 8), 8);
		else if (stacks->a_mxi == stacks->a_topi + 3)
			steps = add_step(NULL, 8);
	}
	exec_free(stacks, &steps);
}

static int		check_a_placement(t_stack *stacks)
{
	int			index;
	int			elem;

	index = stacks->a_mni;
	elem = 4;
	if (stacks->stack_b[stacks->b_topi] < stacks->a_min)
		return (stacks->a_mni);
	else if (stacks->stack_b[stacks->b_topi] > stacks->a_max)
		return (stacks->a_mni);
	while ((index < stacks->size))
	{
		if (stacks->stack_b[stacks->b_topi] < stacks->stack_a[index++])
			return (--index);
		elem--;
	}
	if (elem > 1)
	{
		index = stacks->a_topi;
		while (index != stacks->a_mni)
			if (stacks->stack_b[stacks->b_topi] < stacks->stack_a[index++])
				return (--index);
	}
	return (0);
}

static t_oper	*bravo(t_oper *steps, t_stack *stacks)
{
	int			place;

	place = check_a_placement(stacks);
	if (place == stacks->a_topi)
		;
	else if (place == stacks->a_topi + 1)
		steps = add_step(steps, 5);
	else if (place == stacks->a_topi + 2)
		steps = add_step(add_step(steps, 5), 5);
	else if (place == stacks->a_topi + 3)
		steps = add_step(steps, 8);
	return (add_step(steps, 3));
}

static t_oper	*alpha(t_oper *steps, t_stack *s)
{
	set_stack_a_min_max(s);
	if (s->stack_b[s->b_topi] < s->a_min)
		steps = add_step(steps, 3);
	else if (s->stack_b[s->b_topi] > s->a_max)
		steps = add_step(steps, 3);
	else if (s->stack_b[s->b_topi] < s->stack_a[s->a_topi + 1])
		steps = add_step(add_step(steps, 5), 3);
	else if (s->stack_b[s->b_topi] > s->stack_a[s->a_topi + 1])
		steps = add_step(add_step(steps, 8), 3);
	return (steps);
}

int				quintet(t_stack *stacks, int scene)
{
	t_oper		*steps;

	steps = add_step(NULL, 4);
	if (stacks->a_amt_of_elems == 5 || stacks->size == 5)
		steps = add_step(steps, 4);
	trio(stacks, steps, scene);
	steps = alpha(NULL, stacks);
	exec_free(stacks, &steps);
	if (stacks->size == 5 || stacks->a_amt_of_elems == 5 || scene == 3)
	{
		set_stack_a_min_max(stacks);
		steps = bravo(NULL, stacks);
		exec_free(stacks, &steps);
	}
	sort_a(stacks);
	return (1);
}
