/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:24 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 17:09:12 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_is_empty(t_stack *stacks, char c)
{
	static int a_empty;
	static int b_empty;

	if (c == 'a')
	{
		if ((stacks->a_amt_of_elems < stacks->size) && \
				stacks->a_print_flag == 0)
			a_empty = stacks->size - stacks->a_amt_of_elems;
		if (a_empty && a_empty-- && (stacks->a_print_flag = 1))
			return (1);
		return (0);
	}
	if (c == 'b')
	{
		if ((stacks->b_amt_of_elems < stacks->size) && \
				stacks->b_print_flag == 0)
			b_empty = stacks->size - stacks->b_amt_of_elems;
		if (b_empty && b_empty-- && (stacks->b_print_flag = 1))
			return (1);
		return (0);
	}
	return (0);
}

static void	print_stack_b(int *b_amt_of_elems, int *b_top, t_stack *stacks)
{
	if ((*b_amt_of_elems))
	{
		if (stack_is_empty(stacks, 'b') == 1)
			return ((void)ft_printf("\n"));
		ft_printf("%d\n", stacks->stack_a[(*b_top)]);
		(*b_top)++;
		(*b_amt_of_elems)--;
	}
	else
		ft_printf("\n");
}

static void	print_stack_a(int *a_amt_of_elems, int *a_top, t_stack *stacks,\
		int *i)
{
	ft_printf(" %d| ", (*i)++);
	if ((*a_amt_of_elems))
	{
		if (stack_is_empty(stacks, 'a') == 1)
			return ((void)ft_printf("    "));
		ft_printf("%d   ", stacks->stack_a[(*a_top)]);
		(*a_top)++;
		(*a_amt_of_elems)--;
	}
	else
		ft_printf("    ");
}

static void	print_info(t_stack *stacks, int num, int *index)
{
	if (num == 1 && stacks->count_flag == 0)
		ft_printf("%s - - - - - - - - - - - - - \n\n", stacks->last);
	else if (num == 1)
		ft_printf("%s - - - - - - - - - - - - - %d\n\n", stacks->last,\
				(stacks->amt_of_steps)++);
	else if (num == 2)
	{
		while (*index < stacks->size)
			ft_printf("[%d] \n", (*index)++);
		ft_printf("     _   _\n   A   B\n");
		ft_printf("%29        Top A: %d\n", stacks->a_top);
		ft_printf("%29        Top B: %d\n", stacks->b_top);
		ft_printf("%29Elements in A: %d\n", stacks->a_amt_of_elems);
		ft_printf("%29Elements in B: %d\n", stacks->b_amt_of_elems);
		stacks->a_print_flag = 0;
		stacks->b_print_flag = 0;
	}
}

void		activate_verbose(t_stack *stacks)
{
	int a_top;
	int a_amt_of_elems;
	int b_top;
	int b_amt_of_elems;
	int index;

	if (stacks->verbose_flag == 0)
		return ;
	if (stacks->clear == 1)
		ft_printf("\033[2J\033[1;1H");
	a_top = stacks->a_top;
	a_amt_of_elems = stacks->a_amt_of_elems;
	b_top = stacks->b_top;
	b_amt_of_elems = stacks->b_amt_of_elems;
	index = 0;
	print_info(stacks, 1, &index);
	while (1)
	{
		print_stack_a(&a_amt_of_elems, &a_top, stacks, &index);
		print_stack_b(&b_amt_of_elems, &b_top, stacks);
		if (a_amt_of_elems == 0 && b_amt_of_elems == 0)
			break ;
	}
	print_info(stacks, 2, &index);
}
