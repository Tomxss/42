/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:30:56 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/20 12:31:43 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

int				return_up_a(t_stack *stacks, int index)
{
	int			num;

	if (index == stacks->a_topi)
		return (0);
	num = stacks->a_topi - index;
	if (num < 0)
		num = -1 * num;
	return (num);
}

int				return_down_a(t_stack *stacks, int index)
{
	if (index == stacks->size - 1 && stacks->a_amt_of_elems == 1)
		return (0);
	return (stacks->size - index);
}
