/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10_b_stack_down_rotation.c                      :+:      :+:    :+:   */
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

int				ft_down_b_helper(t_stack *stks, int index)
{
	return (stks->size - index);
}

static void		ft_check_after_max_b(t_stack *s, int *win, int *elem, int index)
{
	int			b_max_index;

	*elem = 0;
	b_max_index = s->b_mxi;
	while (b_max_index < s->size)	//b_max_index < stack_size
	{
		if (s->stk_a[index] > s->stk_b[b_max_index])	//a_top_value > b_max_index
		{
			*win = b_max_index;
			(*elem) = s->elems_b;
			break ;
		}
		b_max_index++;
		(*elem)++;
	}
}

static void		ft_check_before_max_b(t_stack *s, int *win, int index)
{
	int			b_max_index;
	int			top_b;

	b_max_index = s->b_mxi;
	top_b = s->top_b;
	while (top_b != b_max_index)
	{
		if (s->stk_a[index] > s->stk_b[top_b]) //a_top_value > b_top_value
		{
			*win = top_b;
			break ;
		}
		top_b++;
	}
}

int				ft_down_b(t_stack *s, int index)
{
	int			steps;
	int			elem;
	int			winner;

	if (s->stk_a[index] > s->b_max)	//a_top_value > b_max_value
		steps = ft_down_b_helper(s, s->b_mxi);	//steps = stack_size - b_max_index
	else if (s->stk_a[index] < s->b_min)	//a_top_value < b_min_index
		steps = ft_down_b_helper(s, s->b_mxi);	//steps = stack_size - b_max_index
	else
	{
		ft_check_after_max_b(s, &winner, &elem, index);	//increment elem until a_top_value > b_max_value is found and win is set
		if (elem < s->elems_b)	//elements < b_amount_of_elements
			ft_check_before_max_b(s, &winner, index);	//increment top_b until a_top_value > b_top_value is found and win is set
		steps = ft_down_b_helper(s, winner);	//steps = stack_size - b_max_index
	}
	return (steps);
}
