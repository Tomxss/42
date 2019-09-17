/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternative.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:23:11 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:23:13 by tcoetzee         ###   ########.fr       */
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

	ntopb = s->stack_b[s->b_topi];	//stack b's top value
	a_topi = s->a_topi;	//stack a's top indice
	while (a_topi != s->size - 1)	// a indice != stack size - 1
	{
		if (s->stack_a[a_topi] > ntopb && s->stack_a[a_topi] < s->stack_b[s->size - 1])	// a_top_value > b_top_value && a_top_value < b_bot_value
		{
			up_a = return_up_a(s, a_topi);	//if a_top_indice has changed from its original value then "a_top_indice(const) - a_top_indice(variable), if result negative make it positive" else 0
			dw_a = return_down_a(s, a_topi);	//if a_top_indice is the original/variable value with exception(a_amount_of_elements != 1) then "stack_size - a_top_indice" else 0
			if (up_a > dw_a) //Do the smallest one
				return (to_b_down(dw_a));	//for the value of dw_a do rra and then end off with a pb
			else
				return (to_b_up(up_a));	//for the value of up_a do ra and then end off with a pb
		}
		a_topi++;
	}
	return (NULL);
}
