/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_up.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:23:39 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:23:40 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** up B (insert in b)
*/

int				return_up_b_helper(t_stack *stacks, int index)
{
	int			num;

	if (index == stacks->b_topi)	//b_max_indice == b_top_indice
		return (0);	//sa
	num = stacks->b_topi - index; //num = b_top_indice - b_max_indice
	if (num < 0)	//if negative
		num = -1 * num;
	return (num);
}

static void		check_after_max_b(t_stack *s, int *win, int *elem, int index)
{
	int			b_max_index;

	*elem = 0;
	b_max_index = s->b_mxi;
	while (b_max_index < s->size) //b_max_index < stack_size
	{
		if (s->stack_a[index] > s->stack_b[b_max_index])	//a_top_value > b_max_value
		{
			*win = b_max_index;	//since b_max_value IS smaller it wins the check
			(*elem) = s->b_amt_of_elems;	//set elements = b_amount_of_elements
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
		if (s->stack_a[index] > s->stack_b[b_topi])	//a_top_value > b_top_value
		{
			*win = b_topi;
			break ;
		}
		b_topi++;
	}
}

int				return_up_b(t_stack *s, int index)
{
	int			steps;
	int			elem;
	int			winner;

	if (s->stack_a[index] > s->b_max)	//a_top_value > b_max_value
		steps = return_up_b_helper(s, s->b_mxi);	//steps = sa OR top_indice - max_indice
	else if (s->stack_a[index] < s->b_min)	//a_top_value < b_min_value
		steps = return_up_b_helper(s, s->b_mxi);	//steps = sa OR top_indice - max_indice
	else
	{
		check_after_max_b(s, &winner, &elem, index);	//look until you find a_top_value > b_max_value, elem++ for everytime it doesnt find it.
		if (elem < s->b_amt_of_elems)	//amount of elements < b_amount_of_elements then it is before max
			check_before_max_b(s, &winner, index);	// b_topi gets incremented until it finds where a_top_value > b_top_value
		steps = return_up_b_helper(s, winner);	//steps = sa OR top_indice - max_indice
	}
	return (steps);
}
