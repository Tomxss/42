/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:01:46 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 16:02:05 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			atoi_werror(const char *str, int *error)
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
			result += result * 10 + (*str - '0');
			(*error)++;
			str++;
		}
		result = result * sign;
		if ((*str < 48 && *str > 57) || result < MININT || result > MAXINT)
			return (*error = 0);
	}
	return ((int)result);
}

void		free_commands(t_oper **commands)
{
	t_oper	*current;
	t_oper	*head;

	current = *commands;
	if (current == NULL)
		return ;
	while (current)
	{
		head = current->next;
		if (current->operations)
			free(current->operations);
		free(current);
		current = NULL;
		current = head;
	}
	*commands = NULL;
}

void		free_all(int *formatted_input, t_stack *stacks, \
			t_oper **commands, int *flags)
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

int			free_2d_array(char **array, int size)
{
	int	index;

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
