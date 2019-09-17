/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_method_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:41:46 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 16:42:39 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				candidates(int ua, int da, int ub, int db)
{
	int			candidate[5];
	int			index;
	int			winner;

	candidate[0] = ua - ub;
	if (candidate[0] < 0)
		candidate[0] = -candidate[0];
	candidate[1] = da - db;
	if (candidate[1] < 0)
		candidate[1] = -candidate[1];
	candidate[2] = ua + db;
	candidate[3] = da + ub;
	candidate[4] = candidate[0];
	index = 0;
	winner = 0;
	while (index < 4)
	{
		if (candidate[index] <= candidate[4])
		{
			candidate[4] = candidate[index];
			winner = index;
		}
		index++;
	}
	return (winner);
}

void			finalize_stacks(t_stack *stacks)
{
	int		place;

	quintet(stacks, 3);
	while (stacks->b_amt_of_elems)
	{
		place = return_place(stacks);
		rotate_a(stacks, place, 0, 0);
		pa(stacks);
		ft_putstr("pa\n");
	}
	set_a_min_max(stacks);
	rotate_a(stacks, stacks->a_mni, 0, 0);
}

void			free_steps(t_oper **list)
{
	t_oper		*temp;
	t_oper		*head;

	temp = (*list)->head;
	if (!temp)
		return ;
	while (temp)
	{
		head = temp->next;
		free(temp->operations);
		free(temp);
		temp = head;
	}
	*list = NULL;
}
