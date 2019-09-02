/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_7_alternative_checker.c                         :+:      :+:    :+:   */
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

static t_oper		*ft_to_b_up(int up_a)
{
	t_oper			*steps;

	steps = NULL;
	while (up_a > 0)
	{
		steps = ft_add_step(steps, 5);
		up_a--;
	}
	steps = ft_add_step(steps, 4);
	return (steps);
}

static t_oper		*ft_to_b_down(int dw_a)
{
	t_oper			*steps;

	steps = NULL;
	while (dw_a > 0)
	{
		steps = ft_add_step(steps, 8);
		dw_a--;
	}
	steps = ft_add_step(steps, 4);
	return (steps);
}

t_oper				*ft_check_push_to_top_b(t_stack *s)
{
	int				top_a;
	int				ntopb;
	int				up_a;
	int				dw_a;

	ntopb = s->stk_b[s->top_b];	//stack b's top value
	top_a = s->top_a;	//stack a's top indice
	while (top_a != s->size - 1)	// a indice != stack size - 1
	{
		if (s->stk_a[top_a] > ntopb && s->stk_a[top_a] < s->stk_b[s->size - 1])	// a_top_value > b_top_value && a_top_value < b_bot_value
		{
			up_a = ft_up_a(s, top_a);	//if a_top_indice has changed from its original value then "a_top_indice(const) - a_top_indice(variable), if result negative make it positive" else 0
			dw_a = ft_down_a(s, top_a);	//if a_top_indice is the original/variable value with exception(a_amount_of_elements != 1) then "stack_size - a_top_indice" else 0
			if (up_a > dw_a) //Do the smallest one
				return (ft_to_b_down(dw_a));	//for the value of dw_a do rra and then end off with a pb
			else
				return (ft_to_b_up(up_a));	//for the value of up_a do ra and then end off with a pb
		}
		top_a++;
	}
	return (NULL);
}
