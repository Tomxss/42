/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_stack_up_rotation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:15:12 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/07/24 15:15:49 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				ft_up_b_helper(t_stack *stks, int index)
{
	int			num;

	if (index == stks->top_b)
		return (0);
	num = stks->top_b - index;
	if (num < 0)
		num = -1 * num;
	return (num);
}

static void		ft_check_after_max_b(t_stack *s, int *win, int *elem, int index)
{
	int			b_max_index;

	*elem = 0;
	b_max_index = s->b_mxi;
	while (b_max_index < s->size)
	{
		if (s->stk_a[index] > s->stk_b[b_max_index])
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
		if (s->stk_a[index] > s->stk_b[top_b])
		{
			*win = top_b;
			break ;
		}
		top_b++;
	}
}

int				ft_up_b(t_stack *s, int index)
{
	int			steps;
	int			elem;
	int			winner;

	if (s->stk_a[index] > s->b_max)
		steps = ft_up_b_helper(s, s->b_mxi);
	else if (s->stk_a[index] < s->b_min)
		steps = ft_up_b_helper(s, s->b_mxi);
	else
	{
		ft_check_after_max_b(s, &winner, &elem, index);
		if (elem < s->elems_b)
			ft_check_before_max_b(s, &winner, index);
		steps = ft_up_b_helper(s, winner);
	}
	return (steps);
}
