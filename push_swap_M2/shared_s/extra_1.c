/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:46:56 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/20 12:47:34 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void		no_change(t_stack *stacks)
{
	if (stacks->flag == 0)
		return ;
	if (stacks->count == 1)
	{
		ft_printf("%s - - - - - - - - - - - - - %d\n",\
				stacks->last, (stacks->step)++);
	}
	else
		ft_printf("%s - - - - - - - - - - - - -  \n", stacks->last);
	ft_printf("%10s no change\n", stacks->last);
}

int			is_in_order(int *formatted_input, int size)
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
		if (is_in_order(stacks->stack_a, stacks->size) == 1)
			return (1);
		else
			return (-1);
	}
	else
		return (-1);
}

void		free_all(int *formatted_input, t_stack *stacks, t_oper **commands,\
		int *flags)
{
	free(formatted_input);
	if (stacks)
	{
		free(stacks->stack_b);
		free(stacks);
	}
	if (commands)
		free_commands(*&commands);
	free(flags);
}

int			ft_count_words(const char *str, char c)
{
	int i;

	i = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str == c)
			str++;
		i++;
	}
	return (i);
}
