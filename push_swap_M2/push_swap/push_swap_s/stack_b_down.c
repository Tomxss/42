/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_down.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:23:55 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:23:56 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** down B (insert in b)
*/

int				return_down_b_helper(t_stack *stacks, int index)
{
	return (stacks->size - index);
}

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
	int			b_topi;

	b_max_index = s->b_mxi;
	b_topi = s->b_topi;
	while (b_topi != b_max_index)
	{
		if (s->stack_a[index] > s->stack_b[b_topi])
		{
			*win = b_topi;
			break ;
		}
		b_topi++;
	}
}

int				return_down_b(t_stack *s, int index)
{
	int			steps;
	int			elem;
	int			winner;

	if (s->stack_a[index] > s->b_max)
		steps = return_down_b_helper(s, s->b_mxi);
	else if (s->stack_a[index] < s->b_min)
		steps = return_down_b_helper(s, s->b_mxi);
	else
	{
		check_after_max_b(s, &winner, &elem, index);
		if (elem < s->b_amt_of_elems)
			check_before_max_b(s, &winner, index);
		steps = return_down_b_helper(s, winner);
	}
	return (steps);
}
