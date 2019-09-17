/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:14:18 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:14:20 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void				ft_print_history(t_history *history, int flag)
{
	t_history		*copy;

	if (!history)
		return ;
	copy = history->first;
	if (flag == 1)
		ft_printf("log history:\n");
	while (copy)
	{
		if (copy->index == -1 && flag == 1)
		{
			if (copy->oper)
				ft_printf("   ");
		}
		else if (flag == 1)
			ft_printf("%d. ", copy->index);
		if (flag == 1 && copy->index == -1)
		{
			if (copy->oper)
				ft_printf("%s\n", copy->oper);
		}
		else if (copy->index != -1)
			ft_printf("%s\n", copy->oper);
		copy = copy->next;
	}
}

void				ft_clean_the_game_history(t_history **history)
{
	t_history		*copy;
	t_history		*head;

	if (*history == NULL)
		return ;
	copy = (*history)->first;
	while (copy)
	{
		head = copy->next;
		free(copy->oper);
		free(copy);
		copy = NULL;
		copy = head;
	}
	*history = NULL;
	return ;
}

static t_history	*ft_new_history(char *argument)
{
	t_history		*new;
	static int		index;
	int				command;

	new = (t_history*)malloc(sizeof(t_history) * 1);
	new->oper = ft_return_oper_name(argument);
	command = ft_check_game_command(argument);
	new->first = NULL;
	if (command >= 0 && command <= 10)
		new->index = ++index;
	else
		new->index = -1;
	new->next = NULL;
	return (new);
}

t_history			*ft_add_history(t_history **history, char *argument)
{
	t_history		*new;

	new = ft_new_history(argument);
	if (*history != NULL)
	{
		(*history)->next = new;
		new->first = (*history)->first;
		*history = new;
	}
	else
	{
		*history = new;
		new->first = new;
	}
	return (*history);
}
