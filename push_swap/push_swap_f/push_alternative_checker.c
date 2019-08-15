/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_alternative_checker.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:12:31 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/07/24 15:13:18 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

	ntopb = s->stk_b[s->top_b];
	top_a = s->top_a;
	while (top_a != s->size - 1)
	{
		if (s->stk_a[top_a] > ntopb && s->stk_a[top_a] < s->stk_b[s->size - 1])
		{
			up_a = ft_up_a(s, top_a);
			dw_a = ft_down_a(s, top_a);
			if (up_a > dw_a)
				return (ft_to_b_down(dw_a));
			else
				return (ft_to_b_up(up_a));
		}
		top_a++;
	}
	return (NULL);
}
