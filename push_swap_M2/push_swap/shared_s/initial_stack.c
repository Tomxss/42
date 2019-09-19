/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlst_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:26:43 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:26:45 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"
#include <stdio.h>

static void		set_stack_a(t_stack *stacks, int *stack_a, int size)
{
	stacks->stack_a = stack_a;
	stacks->a_topi = 0;
	stacks->a_amt_of_elems = size;
	stacks->a_max = 0;
	stacks->a_min = 0;
	stacks->a_mxi = 0;
	stacks->a_mni = 0;
}

static void		set_stack_b(t_stack *stacks, int size)
{
	stacks->stack_b = (int*)malloc(sizeof(int) * size);
	stacks->b_topi = size - 1;
	stacks->b_amt_of_elems = 0;
	stacks->b_max = 0;
	stacks->b_min = 0;
	stacks->b_mxi = 0;
	stacks->b_mni = 0;
}

static void		set_ext(t_stack *stacks, int *flag, int size)
{
	stacks->size = size;
	stacks->a_buf = 0;
	stacks->b_buf = 0;
	stacks->flag = flag[0];
	stacks->count = flag[1];
	stacks->step = 0;
	stacks->amt_of_ops = 0;
	stacks->clear = 0;
	stacks->print_a = 0;
	stacks->print_b = 0;
	ft_bzero(stacks->last, 4);
	stacks->opnum = -1;
}

t_stack			*initialize_stack(int *stack_a, int size, int *flag)
{
	t_stack		*stacks;

	if (!(stacks = (t_stack*)malloc(sizeof(t_stack) * 1)))
		return (NULL);
	set_stack_a(stacks, stack_a, size);
	set_stack_b(stacks, size);
	if (!stacks->stack_b)
	{
		free(stacks);
		return (NULL);
	}
	set_ext(stacks, flag, size);

	if (flag[0] == 1 || flag[1] == 1)
		activate_verbose(stacks);
	if (flag[2] == 1)
		activate_help();

	return (stacks);
}
