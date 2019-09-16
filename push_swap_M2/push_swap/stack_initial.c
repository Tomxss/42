/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:15:26 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 16:43:47 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_stack_ext(t_stack *stacks, int *flag, int size)
{
	stacks->size = size;
	stacks->a_buf = 0;
	stacks->b_buf = 0;
	stacks->verbose_flag = flag[0];
	stacks->count_flag = flag[1];
	stacks->amt_of_steps = 0;
	stacks->amt_of_ops = 0;
	stacks->clear = 0;
	stacks->a_print_flag = 0;
	stacks->b_print_flag = 0;
	ft_bzero(stacks->last, 4);
	stacks->opnum = -1;
}

static void	set_stack_b(t_stack *stacks, int size)
{
	stacks->stack_b = (int*)malloc(sizeof(int) * size);
	stacks->b_top = size - 1;
	stacks->b_amt_of_elems = 0;
	stacks->b_max = 0;
	stacks->b_min = 0;
	stacks->b_mxi = 0;
	stacks->b_mni = 0;
}

static void	set_stack_a(t_stack *stacks, int *stack_a, int size)
{
	stacks->stack_a = stack_a;
	stacks->a_top = 0;
	stacks->a_amt_of_elems = size;
	stacks->a_max = 0;
	stacks->a_min = 0;
	stacks->a_mxi = 0;
	stacks->a_mni = 0;
}

t_stack		*initiate_stacks(int *stack_a, int size, int *flag)
{
	t_stack *stacks;

	if (!(stacks = (t_stack*)malloc(sizeof(t_stack) * 1)))
		return (NULL);
	set_stack_a(stacks, stack_a, size);
	set_stack_b(stacks, size);
	if (!stacks->stack_b)
	{
		free(stacks);
		return (NULL);
	}
	set_stack_ext(stacks, flag, size);
	if (flag[0])
		activate_verbose(stacks);
	return (stacks);
}
