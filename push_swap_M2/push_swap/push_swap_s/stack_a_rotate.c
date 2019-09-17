/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:23:23 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:23:25 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** Rotation number to be on the top of stack a
*/

int				return_up_a(t_stack *stacks, int index)
{
	int			num;

	if (index == stacks->a_topi)	//a_top_indice(which is incremented as it goes through the loop) == the original a_top_indice
		return (0);	//if so 0 is your answer.
	num = stacks->a_topi - index;	//num = a_top_indice(const) - a_top_indice(variable)
	if (num < 0) // if the number is a negative
		num = -1 * num;	//switch it back to positive.
	return (num);
}

int				return_down_a(t_stack *stacks, int index)
{
	if (index == stacks->size - 1 && stacks->a_amt_of_elems == 1)	//a_top_indice == original_a_top_indice && a_amount_of_elements == 1
		return (0);	//if so 0 in your answer
	return (stacks->size - index);	// stack_size - a_top_indice
}
