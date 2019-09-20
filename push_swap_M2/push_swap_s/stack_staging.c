/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_staging.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:25:43 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/20 12:25:47 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** main algorithm functions 2
*/

static void		upf(t_oper **copy, t_stack *stacks)
{
	t_oper		*head;

	head = (*copy)->next;
	if (stacks->flag == 0)
	{
		ft_putstr((*copy)->oper);
		ft_putchar('\n');
	}
	free((*copy)->oper);
	free((*copy));
	*copy = NULL;
	*copy = head;
}

void			exec_free(t_stack *stacks, t_oper **answers)
{
	t_oper		*copy;
	void		(*oper[11])(t_stack*);

	if (*answers == NULL)
		return ;
	oper[0] = &sa;
	oper[1] = &sb;
	oper[2] = &ss;
	oper[3] = &pa;
	oper[4] = &pb;
	oper[5] = &ra;
	oper[6] = &rb;
	oper[7] = &rr;
	oper[8] = &rra;
	oper[9] = &rrb;
	oper[10] = &rrr;
	copy = (*answers)->head;
	while (copy)
	{
		oper[copy->command](stacks);
		upf(&copy, stacks);
	}
	*answers = NULL;
}

void			set_stack_a_min_max(t_stack *stacks)
{
	int			i;

	i = stacks->a_topi;
	stacks->a_min = stacks->stack_a[i];
	stacks->a_mni = i;
	stacks->a_max = stacks->stack_a[i];
	stacks->a_mxi = i;
	while (i < stacks->size)
	{
		if (stacks->stack_a[i] < stacks->a_min)
		{
			stacks->a_min = stacks->stack_a[i];
			stacks->a_mni = i;
		}
		if (stacks->stack_a[i] > stacks->a_max)
		{
			stacks->a_max = stacks->stack_a[i];
			stacks->a_mxi = i;
		}
		i++;
	}
}

void			set_b_min_max(t_stack *stacks)
{
	int			i;

	i = stacks->b_topi;
	stacks->b_min = stacks->stack_b[i];
	stacks->b_mni = i;
	stacks->b_max = stacks->stack_b[i];
	stacks->b_mxi = i;
	while (i < stacks->size)
	{
		if (stacks->stack_b[i] <= stacks->b_min)
		{
			stacks->b_min = stacks->stack_b[i];
			stacks->b_mni = i;
		}
		if (stacks->stack_b[i] >= stacks->b_max)
		{
			stacks->b_max = stacks->stack_b[i];
			stacks->b_mxi = i;
		}
		i++;
	}
}
