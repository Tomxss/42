/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:21:25 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/20 12:21:58 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** alternative checker
*/

static t_oper		*to_b_up(int up_a)
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

static t_oper		*to_b_down(int dw_a)
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

t_oper				*alternative(t_stack *s)
{
	int				a_topi;
	int				ntopb;
	int				up_a;
	int				dw_a;

	ntopb = s->stack_b[s->b_topi];
	a_topi = s->a_topi;
	while (a_topi != s->size - 1)
	{
		if (s->stack_a[a_topi] > ntopb && s->stack_a[a_topi] \
				< s->stack_b[s->size - 1])
		{
			up_a = return_up_a(s, a_topi);
			dw_a = return_down_a(s, a_topi);
			if (up_a > dw_a)
				return (to_b_down(dw_a));
			else
				return (to_b_up(up_a));
		}
		a_topi++;
	}
	return (NULL);
}
