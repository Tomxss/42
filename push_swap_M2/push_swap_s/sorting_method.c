/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_method.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:24:21 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/20 12:24:44 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static t_oper	*check_steps(t_stack *stacks, int index)
{
	int			up_a;
	int			up_b;
	int			down_a;
	int			down_b;
	int			winner;

	set_b_min_max(stacks);
	up_a = return_up_a(stacks, index);
	down_a = return_down_a(stacks, index);
	up_b = return_up_b(stacks, index);
	down_b = return_down_b(stacks, index);
	winner = candidates(up_a, down_a, up_b, down_b);
	if (winner == 0)
		return (ua_ub(up_a, up_b));
	else if (winner == 1)
		return (da_db(down_a, down_b));
	else if (winner == 2)
		return (ua_db(up_a, down_b));
	else if (winner == 3)
		return (da_ub(down_a, up_b));
	else
		return (NULL);
}

static t_oper	*internal_loop(t_stack *s, int in, int ex, int num_oper)
{
	t_oper		*candidate;
	t_oper		*answer;

	answer = NULL;
	while (in < s->size)
	{
		if (!(candidate = check_steps(s, in)))
			break ;
		if (in == ex)
		{
			num_oper = candidate->head->num;
			answer = candidate;
		}
		else if (candidate->head->num <= num_oper)
		{
			free_steps(&answer);
			num_oper = candidate->head->num;
			answer = candidate;
		}
		else
			free_steps(&candidate);
		in++;
	}
	return (answer);
}

static int		loop(t_stack *stacks, int i, t_oper *steps, t_oper *alt)
{
	while (i < stacks->size)
	{
		steps = NULL;
		if (i <= 1)
			steps = add_step(steps, 4);
		else
		{
			alt = alternative(stacks);
			steps = internal_loop(stacks, i, i, 0);
			if (alt && alt->head->num <= steps->head->num)
			{
				free_steps(&steps);
				steps = alt;
			}
			else if (alt)
				free_steps(&alt);
		}
		exec_free(stacks, &steps);
		i++;
		if (stacks->a_amt_of_elems == 5)
			break ;
	}
	clean_a(stacks);
	return (1);
}

int				push_swap(t_stack *stacks)
{
	if (is_stack_in_order(stacks) == 1)
		return (1);
	else if (stacks->size == 2)
		return (duo(stacks));
	else if (stacks->size == 3)
		return (trio(stacks, NULL, 1));
	else if (stacks->size <= 5)
		return (quintet(stacks, 2));
	else if (loop(*&stacks, 0, NULL, NULL) == -1)
		return (-1);
	else
		return (1);
}
