/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:24:28 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 16:24:57 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_after_max_b(t_stack *s, int *win, int *elem, int index)
{
	int			b_max_index;

	*elem = 0;
	b_max_index = s->b_mxi;
	while (b_max_index < s->size)
	{
		if (s->stack_a[index] > s->stack_b[b_max_index])
		{
			*win = b_max_index;
			(*elem) = s->b_amt_of_elems;
			break ;
		}
		b_max_index++;
		(*elem)++;
	}
}

static void		check_before_max_b(t_stack *s, int *win, int index)
{
	int			b_max_index;
	int			b_top;

	b_max_index = s->b_mxi;
	b_top = s->b_top;
	while (b_top != b_max_index)
	{
		if (s->stack_a[index] > s->stack_b[b_top])
		{
			*win = b_top;
			break ;
		}
		b_top++;
	}
}

int				return_down_b(t_stack *s, int index)
{
	int			steps;
	int			elem;
	int			winner;

	if (s->stack_a[index] > s->b_max)
		steps = down_b_helper(s, s->b_mxi);
	else if (s->stack_a[index] < s->b_min)
		steps = down_b_helper(s, s->b_mxi);
	else
	{
		check_after_max_b(s, &winner, &elem, index);
		if (elem < s->b_amt_of_elems)
			check_before_max_b(s, &winner, index);
		steps = down_b_helper(s, winner);
	}
	return (steps);
}

int				up_b_helper(t_stack *stacks, int index)
{
	int			num;

	if (index == stacks->b_top)
		return (0);
	num = stacks->b_top - index;
	if (num < 0)
		num = -1 * num;
	return (num);
}

int				return_up_b(t_stack *s, int index)
{
	int			steps;
	int			elem;
	int			winner;

	if (s->stack_a[index] > s->b_max)
		steps = up_b_helper(s, s->b_mxi);
	else if (s->stack_a[index] < s->b_min)
		steps = up_b_helper(s, s->b_mxi);
	else
	{
		check_after_max_b(s, &winner, &elem, index);
		if (elem < s->b_amt_of_elems)
			check_before_max_b(s, &winner, index);
		steps = up_b_helper(s, winner);
	}
	return (steps);
}
