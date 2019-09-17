/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_amt_of_ops_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:27:17 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:27:18 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** reverse rotate a - shift down all elements of stack a by 1.
** The last element becomes the first one.
*/

void			rra(t_stack *stacks)
{
	int			elems;
	int			size;

	ft_strcpy(stacks->last, "rra");
	stacks->opnum = 8;
	if (stacks->a_amt_of_elems < 2)
		return (no_change(stacks));
	elems = stacks->a_amt_of_elems;
	size = (stacks->size) - 1;
	stacks->a_buf = stacks->stack_a[((stacks->size) - 1)];
	while (elems > 0)
	{
		stacks->stack_a[size] = stacks->stack_a[size - 1];
		size--;
		if (size == 0)
			break ;
		elems--;
	}
	stacks->stack_a[stacks->a_topi] = stacks->a_buf;
	activate_verbose(stacks);
}

/*
** reverse rotate b - shift down all elements of stack b by 1.
** The last element becomes the first one.
*/

void			rrb(t_stack *stacks)
{
	int			elems;
	int			size;

	ft_strcpy(stacks->last, "rrb");
	stacks->opnum = 9;
	if (stacks->b_amt_of_elems < 2)
		return (no_change(stacks));
	elems = stacks->b_amt_of_elems;
	size = (stacks->size) - 1;
	stacks->b_buf = stacks->stack_b[((stacks->size) - 1)];
	while (elems > 0)
	{
		stacks->stack_b[size] = stacks->stack_b[size - 1];
		size--;
		if (size == 0)
			break ;
		elems--;
	}
	stacks->stack_b[stacks->b_topi] = stacks->b_buf;
	activate_verbose(stacks);
}

/*
** rra and rrb at the same time.
*/

void			rrr(t_stack *stacks)
{
	int			buffer;

	ft_strcpy(stacks->last, "rrr");
	stacks->opnum = 10;
	if (stacks->a_amt_of_elems < 2 || stacks->b_amt_of_elems < 2)
		return (no_change(stacks));
	buffer = stacks->flag;
	stacks->flag = 0;
	rra(stacks);
	rrb(stacks);
	stacks->flag = buffer;
	ft_strcpy(stacks->last, "rrr");
	activate_verbose(stacks);
}
