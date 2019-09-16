/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:56:26 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 16:59:25 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** static void		upf(t_oper **copy, t_stack *stacks)
**{
**	t_oper		*holder;
**
**	holder = (*copy)->next;
**	if (stacks->count_flag == 0)
**	{
**		ft_putstr((*copy)->operations);
**		ft_putchar('\n');
**	}
**	free((*copy)->operations);
**	free((*copy));
**	*copy = NULL;
**	*copy = holder;
**}
*/

static int	return_brother(t_stack *s)
{
	int		index;
	int		b;
	int		a;

	index = s->a_top;
	a = s->stack_a[s->a_top];
	b = s->stack_b[s->b_top];
	while (index < s->size)
	{
		if (b < s->stack_a[index] && a > s->stack_a[index])
			return (index);
		index++;
	}
	return (-1);
}

int			return_place(t_stack *stacks)
{
	int		index;
	int		b;
	int		brother;

	index = stacks->a_top;
	b = stacks->stack_b[stacks->b_top];
	set_a_min_max(stacks);
	if ((brother = return_brother(stacks)) != -1)
		return (brother);
	if (b > stacks->a_max)
		return (stacks->a_mni);
	if (b < stacks->a_min)
		return (stacks->a_mni);
	while (index != stacks->size - 1)
	{
		if (b < stacks->stack_a[index])
			return (index);
		else if (b > stacks->stack_a[index] && b < stacks->stack_a[index + 1]
				&& stacks->stack_a[index + 1] == stacks->size - 1)
			return (index + 1);
		else if (b > stacks->stack_a[index] && b < stacks->stack_a[index + 1])
			return (index + 1);
		index++;
	}
	return (0);
}

void		rotate_a(t_stack *stacks, int place, int up_a, int down_a)
{
	int		num;

	set_a_min_max(stacks);
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
				if (stacks->count_flag == 0)
					ft_putstr("ra\n");
			}
			else
			{
				rra(stacks);
				if (stacks->count_flag == 0)
					ft_putstr("rra\n");
			}
		}
	}
}
