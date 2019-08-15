/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_op_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:28:15 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/07/24 15:29:01 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void		sa(t_stack *stks)
{
	int		top;

	ft_strcpy(stks->last, "sa");
	stks->opnum = 0;
	if (stks->elems_a < 2)
		return (ft_no_change(stks));
	top = stks->top_a;
	stks->buf_a = stks->stk_a[top];
	stks->stk_a[top] = stks->stk_a[top + 1];
	stks->stk_a[top + 1] = stks->buf_a;
	ft_print_stacks(stks);
}

void		sb(t_stack *stks)
{
	int		top;

	ft_strcpy(stks->last, "sb");
	stks->opnum = 1;
	if (stks->elems_b < 2)
		return (ft_no_change(stks));
	top = stks->top_b;
	stks->buf_b = stks->stk_b[top];
	stks->stk_b[top] = stks->stk_b[top + 1];
	stks->stk_b[top + 1] = stks->buf_b;
	ft_print_stacks(stks);
}

void		ss(t_stack *stks)
{
	int		buffer;

	ft_strcpy(stks->last, "ss");
	stks->opnum = 2;
	if (stks->elems_a < 2 || stks->elems_b < 2)
		return (ft_no_change(stks));
	buffer = stks->flag;
	stks->flag = 0;
	sa(stks);
	sb(stks);
	stks->flag = buffer;
	ft_strcpy(stks->last, "ss");
	ft_print_stacks(stks);
}

void		pa(t_stack *stks)
{
	int		size;

	ft_strcpy(stks->last, "pa");
	stks->opnum = 3;
	if (stks->elems_b == 0)
		return (ft_no_change(stks));
	size = stks->size - 1;
	if (stks->top_a == size && stks->elems_a == 0)
		stks->stk_a[(stks->top_a)] = stks->stk_b[(stks->top_b)];
	else
	{
		stks->stk_a[((stks->top_a) - 1)] = stks->stk_b[(stks->top_b)];
		(stks->top_a)--;
	}
	if (stks->top_b != size)
		(stks->top_b)++;
	else
		stks->top_b = size;
	(stks->elems_b)--;
	(stks->elems_a)++;
	ft_print_stacks(stks);
}

void		pb(t_stack *stks)
{
	int		size;

	ft_strcpy(stks->last, "pb");
	stks->opnum = 4;
	if (stks->elems_a == 0)
		return (ft_no_change(stks));
	size = (stks->size - 1);
	if (stks->top_b == size && stks->elems_b == 0)
		stks->stk_b[(stks->top_b)] = stks->stk_a[(stks->top_a)];
	else
	{
		stks->stk_b[((stks->top_b) - 1)] = stks->stk_a[(stks->top_a)];
		(stks->top_b)--;
	}
	if (stks->top_a != size)
		(stks->top_a)++;
	else
		stks->top_a = size;
	(stks->elems_a)--;
	(stks->elems_b)++;
	ft_print_stacks(stks);
}
