/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_method_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:39:32 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 16:41:31 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	EVERYTHING TO DO WITH STEPS
*/

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

static t_oper	*internal_loop(t_stack *stacks, int in, int ex, int num_oper)
{
	t_oper		*candidate;
	t_oper		*answer;

	answer = NULL;
	while (in < stacks->size)
	{
		if (!(candidate = check_steps(stacks, in)))
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

t_oper			*alternative_loop(t_stack *stacks)
{
	int				a_top;
	int				ntopb;
	int				up_a;
	int				dw_a;

	ntopb = stacks->stack_b[stacks->b_top];
	a_top = stacks->a_top;
	while (a_top != stacks->size - 1)
	{
		if (stacks->stack_a[a_top] > ntopb && stacks->stack_a[a_top]\
				< stacks->stack_b[stacks->size - 1])
		{
			up_a = return_up_a(stacks, a_top);
			dw_a = return_down_a(stacks, a_top);
			if (up_a > dw_a)
				return (to_b_down(dw_a));
			else
				return (to_b_up(up_a));
		}
		a_top++;
	}
	return (NULL);
}
