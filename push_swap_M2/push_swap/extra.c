/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:14:54 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/05 11:14:56 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_operation(t_oper **temp, t_stack *stacks)
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

void 				exec_free(t_stack *stacks, t_oper **results)
{
	t_oper	*temp;
	void 		(*oper[11])(t_stack*);

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

static int	atoi_werror(const char *str, int *error)
{
	long long result;
	long long sign;

	sign = 1;
	result = 0;
	*error = 0;
	if (str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str == '-')
			sign = -1;
		if (*str == '-' || *str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
				result =+ result * 10 + (*str - '0');
				(*error)++;
				str++;
		}
		result = result * sign;
		if (*str < 48 && *str > 57) || result < MININT || result > MAXINT)
			return (*error = 0);
	}
	return ((int)result);
}

void free_commands(t_oper **commands)
{
	t_oper	*current;
	t_oper	*head;

	current = *commands;
	if (current == NULL)
		return ;
	while (current)
	{
		head = current->next;
		if (current->oper)
			free(current->oper);
		free(current);
		current = NULL;
		current = head;
	}
	*commands = NULL;
}

void free_all(int *formatted_input, t_stack *stacks, t_oper **commands, int *flags)
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

int free_2d_array(char **array, int size)
{
	int  index;

	index = 0;
	if (!array)
		return (-1);
	while (index < size)
	{
		if (array[index])
			free(array[index]);
		index++;
	}
	free(array);
	return (-1);
}
