/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:27:05 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:27:07 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rotate a - shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

void			ra(t_stack *stacks)
{
	int			elems;
	int			top;

	ft_strcpy(stacks->last, "ra");
	stacks->opnum = 5;
	if (stacks->a_amt_of_elems < 2)
		return (no_change(stacks));
	elems = stacks->a_amt_of_elems;
	top = stacks->a_top;
	stacks->a_buf = stacks->stack_a[top];
	while (elems > 0)
	{
		if ((top + 1) == stacks->size - 1)
		{
			stacks->stack_a[top] = stacks->stack_a[top + 1];
			break ;
		}
		stacks->stack_a[top] = stacks->stack_a[top + 1];
		top++;
		elems--;
	}
	stacks->stack_a[((stacks->size) - 1)] = stacks->a_buf;
	activate_verbose(stacks);
}

/*
** rotate b - shift up all elements of stack b by 1.
** The first element becomes the last one.
*/

void			rb(t_stack *stacks)
{
	int			elems;
	int			top;

	ft_strcpy(stacks->last, "rb");
	stacks->opnum = 6;
	if (stacks->b_amt_of_elems < 2)
		return (no_change(stacks));
	elems = stacks->b_amt_of_elems;
	top = stacks->b_top;
	stacks->b_buf = stacks->stack_b[top];
	while (elems > 0)
	{
		if ((top + 1) < stacks->size)
		{
			stacks->stack_b[top] = stacks->stack_b[top + 1];
			top++;
		}
		elems--;
	}
	stacks->stack_b[((stacks->size) - 1)] = stacks->b_buf;
	activate_verbose(stacks);
}

/*
**  ra and rb at the same time.
*/

void			rr(t_stack *stacks)
{
	int			buffer;

	ft_strcpy(stacks->last, "rr");
	stacks->opnum = 7;
	if (stacks->a_amt_of_elems < 2 || stacks->b_amt_of_elems < 2)
		return (no_change(stacks));
	buffer = stacks->count_flag;
	stacks->count_flag = 0;
	ra(stacks);
	rb(stacks);
	stacks->count_flag = buffer;
	ft_strcpy(stacks->last, "rr");
	activate_verbose(stacks);
}
