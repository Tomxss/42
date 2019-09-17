/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_amt_of_ops_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:26:55 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:26:56 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** swap a - swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements).
*/

void		sa(t_stack *stacks)
{
	int		top;

	ft_strcpy(stacks->last, "sa");
	stacks->opnum = 0;
	if (stacks->a_amt_of_elems < 2)
		return (no_change(stacks));
	top = stacks->a_topi;
	stacks->a_buf = stacks->stack_a[top];
	stacks->stack_a[top] = stacks->stack_a[top + 1];
	stacks->stack_a[top + 1] = stacks->a_buf;
	activate_verbose(stacks);
}

/*
** swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements).
*/

void		sb(t_stack *stacks)
{
	int		top;

	ft_strcpy(stacks->last, "sb");
	stacks->opnum = 1;
	if (stacks->b_amt_of_elems < 2)
		return (no_change(stacks));
	top = stacks->b_topi;
	stacks->b_buf = stacks->stack_b[top];
	stacks->stack_b[top] = stacks->stack_b[top + 1];
	stacks->stack_b[top + 1] = stacks->b_buf;
	activate_verbose(stacks);
}

/*
** sa and sb at the same time.
*/

void		ss(t_stack *stacks)
{
	int		buffer;

	ft_strcpy(stacks->last, "ss");
	stacks->opnum = 2;
	if (stacks->a_amt_of_elems < 2 || stacks->b_amt_of_elems < 2)
		return (no_change(stacks));
	buffer = stacks->flag;
	stacks->flag = 0;
	sa(stacks);
	sb(stacks);
	stacks->flag = buffer;
	ft_strcpy(stacks->last, "ss");
	activate_verbose(stacks);
}

/*
** push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

void		pa(t_stack *stacks)
{
	int		size;

	ft_strcpy(stacks->last, "pa");
	stacks->opnum = 3;
	if (stacks->b_amt_of_elems == 0)
		return (no_change(stacks));
	size = stacks->size - 1;
	if (stacks->a_topi == size && stacks->a_amt_of_elems == 0)
		stacks->stack_a[(stacks->a_topi)] = stacks->stack_b[(stacks->b_topi)];
	else
	{
		stacks->stack_a[((stacks->a_topi) - 1)] = stacks->stack_b[(stacks->b_topi)];
		(stacks->a_topi)--;
	}
	if (stacks->b_topi != size)
		(stacks->b_topi)++;
	else
		stacks->b_topi = size;
	(stacks->b_amt_of_elems)--;
	(stacks->a_amt_of_elems)++;
	activate_verbose(stacks);
}

/*
** push b - take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void		pb(t_stack *stacks)
{
	int		size;

	ft_strcpy(stacks->last, "pb");
	stacks->opnum = 4;
	if (stacks->a_amt_of_elems == 0)
		return (no_change(stacks));
	size = (stacks->size - 1);
	if (stacks->b_topi == size && stacks->b_amt_of_elems == 0)
		stacks->stack_b[(stacks->b_topi)] = stacks->stack_a[(stacks->a_topi)];
	else
	{
		stacks->stack_b[((stacks->b_topi) - 1)] = stacks->stack_a[(stacks->a_topi)];
		(stacks->b_topi)--;
	}
	if (stacks->a_topi != size)
		(stacks->a_topi)++;
	else
		stacks->a_topi = size;
	(stacks->a_amt_of_elems)--;
	(stacks->b_amt_of_elems)++;
	activate_verbose(stacks);
}
