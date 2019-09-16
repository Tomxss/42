/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:14:54 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 15:58:29 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			isinorder(int *formatted_input, int size)
{
	int		index;

	index = 0;
	while (index < size - 1)
	{
		if (formatted_input[index] < formatted_input[index + 1])
			index++;
		else
			return (0);
	}
	return (1);
}

int			is_stack_in_order(t_stack *stacks)
{
	if (stacks->b_amt_of_elems == 0)
	{
		if (isinorder(stacks->stack_a, stacks->size) == 1)
			return (1);
		else
			return (-1);
	}
	else
		return (-1);
}

void		no_change(t_stack *stacks)
{
	if (stacks->count_flag == 0)
		return ;
	ft_printf("%s - - - - - - - - - - - - - %d\n",
			stacks->last, (stacks->amt_of_steps)++);
	ft_printf("%10s no change\n", stacks->last);
}

static void	print_operation(t_oper **temp, t_stack *stacks)
{
	t_oper *head;

	head = (*temp)->next;
	if (stacks->verbose_flag == 0)
	{
		ft_putstr((*temp)->operations);
		ft_putchar('\n');
	}
	free((*temp)->operations);
	free((*temp));
	*temp = NULL;
	*temp = head;
}

void		exec_free(t_stack *stacks, t_oper **results)
{
	t_oper		*temp;
	void		(*oper[11])(t_stack*);

	if (*results == NULL)
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
	temp = (*results)->head;
	while (temp)
	{
		oper[temp->command](stacks);
		print_operation(&temp, stacks);
	}
	*results = NULL;
}
