/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:26:05 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:26:07 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_oper				*new_oper(char *str)
{
	t_oper			*new;

	new = (t_oper*)malloc(sizeof(t_oper) * 1);
	new->oper = str;
	new->command = -1;
	new->num = 0;
	new->next = NULL;
	new->head = NULL;
	return (new);
}

void				add_oper(t_oper **commands, t_oper **new)
{
	static t_oper	*head;
	static int		flag;

	if (*commands != NULL)
	{
		if (flag == 0)
			head = *new;
		if (flag > 0)
		{
			head->next = *new;
			head = *new;
		}
		else
			(*commands)->next = *new;
		flag = 1;
	}
	else
		*commands = *new;
}

void				free_commands(t_oper **commands)
{
	t_oper			*copy;
	t_oper			*head;

	copy = *commands;
	if (copy == NULL)
		return ;
	while (copy)
	{
		head = copy->next;
		if (copy->oper)
			free(copy->oper);
		free(copy);
		copy = NULL;
		copy = head;
	}
	*commands = NULL;
}

void				print_commands(t_oper *commands)
{
	t_oper		*copy;

	copy = commands;
	if (!copy)
		return ;
	while (copy)
	{
		ft_printf("%s\n", copy->oper);
		copy = copy->next;
	}
}
