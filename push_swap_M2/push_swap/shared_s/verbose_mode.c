/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_verbose.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:27:30 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:27:32 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static int		is_empty(t_stack *stacks, char ch)
{
	static int	empty_a;
	static int	empty_b;

	if (ch == 'a')
	{
		if ((stacks->a_amt_of_elems < stacks->size) && stacks->print_a == 0)
			empty_a = stacks->size - stacks->a_amt_of_elems;
		if (empty_a && empty_a-- && (stacks->print_a = 1))
			return (1);
		return (0);
	}
	if (ch == 'b')
	{
		if ((stacks->b_amt_of_elems < stacks->size) && stacks->print_b == 0)
			empty_b = stacks->size - stacks->b_amt_of_elems;
		if (empty_b && empty_b-- && (stacks->print_b = 1))
			return (1);
		return (0);
	}
	return (0);
}

static void		print_stack_b(int *elem_b, int *b_topi, t_stack *stacks)
{
	if ((*elem_b))
	{
		if (is_empty(stacks, 'b') == 1)
			return ((void)ft_printf("\n"));
		ft_printf("%d\n", stacks->stack_b[(*b_topi)]);
		(*b_topi)++;
		(*elem_b)--;
	}
	else
		ft_printf("\n");
}

static void		print_stack_a(int *elem_a, int *a_topi, t_stack *stacks, int *i)
{
	ft_printf(" %d| ", (*i)++);
	if ((*elem_a))
	{
		if (is_empty(stacks, 'a') == 1)
			return ((void)ft_printf("    "));
		ft_printf("%d   ", stacks->stack_a[(*a_topi)]);
		(*a_topi)++;
		(*elem_a)--;
	}
	else
		ft_printf("    ");
}

static void		print_info(t_stack *stacks, int num, int *index)
{
	if (num == 1)
		ft_printf("%s - - - - - - - - - - - - - %d\n\n",
	stacks->last, (stacks->step)++);
	else if (num == 2)
	{
		while (*index < stacks->size)
			ft_printf("[%d] \n", (*index)++);
		ft_printf("    _   _\n    a   b\n");
		ft_printf("%29  top a:   %d\n", stacks->a_topi);
		ft_printf("%29  top b:   %d\n", stacks->b_topi);
		ft_printf("%29elems a: %d\n", stacks->a_amt_of_elems);
		ft_printf("%29elems b: %d\n\n", stacks->b_amt_of_elems);
		stacks->print_a = 0;
		stacks->print_b = 0;
	}
}

void			activate_verbose(t_stack *stacks)
{
	int			a_topi;
	int			elem_a;
	int			b_topi;
	int			elem_b;
	int			index;

	if (stacks->flag == 0)
		return ;
	if (stacks->clear == 1)
		ft_printf("\033[2J\033[1;1H");
	a_topi = stacks->a_topi;
	elem_a = stacks->a_amt_of_elems;
	b_topi = stacks->b_topi;
	elem_b = stacks->b_amt_of_elems;
	index = 0;
	print_info(stacks, 1, &index);
	while (1)
	{
		print_stack_a(&elem_a, &a_topi, stacks, &index);
		print_stack_b(&elem_b, &b_topi, stacks);
		if (elem_a == 0 && elem_b == 0)
			break ;
	}
	print_info(stacks, 2, &index);
}
