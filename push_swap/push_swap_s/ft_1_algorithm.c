/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:21:52 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:21:54 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** main algorithm
*/

static t_oper	*ft_check_steps(t_stack *stks, int index)
{
	int			up_a;
	int			up_b;
	int			down_a;
	int			down_b;
	int			winner;

	ft_set_min_max_b(stks);
	up_a = ft_up_a(stks, index);	//rra : if a_top_indice has changed from its original value then "a_top_indice(const) - a_top_indice(variable), if result negative make it positive" else 0
	down_a = ft_down_a(stks, index);	//ra : //if a_top_indice is the original/variable value with exception(a_amount_of_elements != 1) then "stack_size - a_top_indice" else 0
	up_b = ft_up_b(stks, index);	//rrb?	//sa OR top_indice - max_indice
	down_b = ft_down_b(stks, index);	//rb?
	winner = ft_candidates(up_a, down_a, up_b, down_b);
	if (winner == 0)
		return (ft_ua_ub(up_a, up_b));
	else if (winner == 1)
		return (ft_da_db(down_a, down_b));
	else if (winner == 2)
		return (ft_ua_db(up_a, down_b));
	else if (winner == 3)
		return (ft_da_ub(down_a, up_b));
	else
		return (NULL);
}

static t_oper	*ft_internal_loop(t_stack *s, int in, int ex, int num_oper)
{
	t_oper		*candidate;
	t_oper		*answer;

	answer = NULL;
	while (in < s->size)	//indice(given) < stack_size
	{
		if (!(candidate = ft_check_steps(s, in)))	//
			break ;	//if there are no candidates then break out of while loop.
		if (in == ex)
		{
			num_oper = candidate->holder->num;
			answer = candidate;
		}
		else if (candidate->holder->num <= num_oper)
		{
			ft_free_steps(&answer);
			num_oper = candidate->holder->num;
			answer = candidate;
		}
		else
			ft_free_steps(&candidate);
		in++;
	}
	return (answer);
}

static int		ft_main_loop(t_stack *stks, int i, t_oper *steps, t_oper *alt)
{
	while (i < stks->size)
	{
		steps = NULL;
		if (i <= 1)
			steps = ft_add_step(steps, 4);
		else
		{
			alt = ft_check_push_to_top_b(stks); //checks whether it would be a good idea to do pb and organises a in the best way to do the best pb
			steps = ft_internal_loop(stks, i, i, 0);
			if (alt && alt->holder->num <= steps->holder->num)
			{
				ft_free_steps(&steps);
				steps = alt;
			}
			else if (alt)
				ft_free_steps(&alt);
		}
		ft_use_print_and_free(stks, &steps);
		i++;
		if (stks->elems_a == 5)
			break ;
	}
	ft_make_nice_a_and_say_bye_to_b(stks);
	return (1);
}

int				ft_push_swap(t_stack *stks)
{
	if (ft_is_stack_in_order(stks) == 1)
		return (1);
	else if (stks->size == 2)
		return (ft_eq_2(stks));
	else if (stks->size == 3)
		return (ft_eq_3(stks, NULL, 1));
	else if (stks->size <= 5)
		return (ft_eq_5(stks, 2));
	else if (ft_main_loop(*&stks, 0, NULL, NULL) == -1)
		return (-1);
	else
		return (1);
}
