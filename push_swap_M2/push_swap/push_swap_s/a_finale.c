/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_finale.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:24:09 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:24:10 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static int		return_brother(t_stack *s)
{
	int		index;
	int		b;
	int		a;

	index = s->a_topi;
	a = s->stack_a[s->a_topi];
	b = s->stack_b[s->b_topi];
	while (index < s->size)
	{
		if (b < s->stack_a[index] && a > s->stack_a[index])
			return (index);
		index++;
	}
	return (-1);
}

static int		return_place(t_stack *s)
{
	int		index;
	int		b;
	int		brother;

	index = s->a_topi;
	b = s->stack_b[s->b_topi];
	set_stack_a_min_max(s);
	if ((brother = return_brother(s)) != -1)
		return (brother);
	if (b > s->a_max)
		return (s->a_mni);
	if (b < s->a_min)
		return (s->a_mni);
	while (index != s->size - 1)
	{
		if (b < s->stack_a[index])
			return (index);
		else if (b > s->stack_a[index] && b < s->stack_a[index + 1]
				&& s->stack_a[index + 1] == s->size - 1)
			return (index + 1);
		else if (b > s->stack_a[index] && b < s->stack_a[index + 1])
			return (index + 1);
		index++;
	}
	return (0);
}

static void		rotate_a(t_stack *stacks, int place, int up_a, int down_a)
{
	int		num;

	set_stack_a_min_max(stacks);
	up_a = return_up_a(stacks, place);
	down_a = return_down_a(stacks, place);
	num = down_a;
	(up_a <= down_a) ? (num = up_a) : (num);
	if (stacks->a_mni != 0)
	{
		while (num--)
		{
			if (up_a < down_a)
			{
				ra(stacks);
				if (stacks->flag == 0)
					ft_putstr("ra\n");
			}
			else
			{
				rra(stacks);
				if (stacks->flag == 0)
					ft_putstr("rra\n");
			}
		}
	}
}

void			clean_a(t_stack *stacks)
{
	int		place;

	quintet(stacks, 3);
	while (stacks->b_amt_of_elems)
	{
		place = return_place(stacks);
		rotate_a(stacks, place, 0, 0);
		pa(stacks);
		ft_putstr("pa\n");
	}
	set_stack_a_min_max(stacks);
	rotate_a(stacks, stacks->a_mni, 0, 0);
}
