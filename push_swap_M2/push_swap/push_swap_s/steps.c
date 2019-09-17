/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:22:34 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:22:36 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** main algorithm functions 1
*/

static char		*return_name(int oper)
{
	if (oper == 0)
		return (ft_strdup("sa"));
	else if (oper == 1)
		return (ft_strdup("sb"));
	else if (oper == 2)
		return (ft_strdup("ss"));
	else if (oper == 3)
		return (ft_strdup("pa"));
	else if (oper == 4)
		return (ft_strdup("pb"));
	else if (oper == 5)
		return (ft_strdup("ra"));
	else if (oper == 6)
		return (ft_strdup("rb"));
	else if (oper == 7)
		return (ft_strdup("rr"));
	else if (oper == 8)
		return (ft_strdup("rra"));
	else if (oper == 9)
		return (ft_strdup("rrb"));
	else if (oper == 10)
		return (ft_strdup("rrr"));
	else
		return (NULL);
}

static t_oper	*new_step(int oper)
{
	t_oper		*new;

	new = (t_oper*)malloc(sizeof(t_oper) * 1);
	if (!new)
		return (NULL);
	new->oper = return_name(oper);
	if (!new->oper)
	{
		free(new);
		return (NULL);
	}
	new->command = oper;
	new->num = 1;
	new->head = NULL;
	new->next = NULL;
	return (new);
}

t_oper			*add_step(t_oper *step, int oper)
{
	t_oper		*new;

	if (!(new = new_step(oper)))
		return (NULL);
	if (step)
	{
		step->next = new;
		new->head = step->head;
		step->head->num = ++(step->head->num);
		step = new;
	}
	else
	{
		new->head = new;
		step = new;
	}
	return (step);
}

void			free_steps(t_oper **list)
{
	t_oper		*copy;
	t_oper		*head;

	copy = (*list)->head;
	if (!copy)
		return ;
	while (copy)
	{
		head = copy->next;
		free(copy->oper);
		free(copy);
		copy = head;
	}
	*list = NULL;
}
