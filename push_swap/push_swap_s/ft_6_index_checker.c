/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_6_index_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:22:57 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:23:00 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** challenge for up and down variations
*/

t_oper			*ft_ua_ub(int ua, int ub)
{
	t_oper		*steps;
	int			num;

	steps = NULL;
	if (ua > ub)	//up_a_step_num > up_b_step_num
		num = ua;
	else
		num = ub;
	while (num--)
	{
		if (ua > 0 && ub > 0)	// up_a_step_num is positive && up_b_step_num is positive
		{
			steps = ft_add_step(steps, 7);	//rr
		}
		else
		{
			if (ua > 0)
				steps = ft_add_step(steps, 5);	//ra
			if (ub > 0)
				steps = ft_add_step(steps, 6);	//rb
		}
		ua--;
		ub--;
	}
	return (ft_add_step(steps, 4));	//pb
}

t_oper			*ft_da_db(int da, int db)
{
	t_oper		*steps;
	int			num;

	steps = NULL;
	if (da > db)
		num = da;
	else
		num = db;
	while (num--)
	{
		if (da > 0 && db > 0)	//down_a is positive && down_b is positive
			steps = ft_add_step(steps, 10);	//rrr
		else
		{
			if (da > 0)//only down_a is positive
				steps = ft_add_step(steps, 8);	//rra
			if (db > 0)//only down_b is positive
				steps = ft_add_step(steps, 9);	//rrb
		}
		if (da > 0)
			da--;
		if (db > 0)
			db--;
	}
	return (ft_add_step(steps, 4));	//pb
}

t_oper			*ft_ua_db(int ua, int db)
{
	t_oper		*steps;
	int			num;

	steps = NULL;
	num = ua + db;
	while (num)
	{
		if (ua > 0)
			steps = ft_add_step(steps, 5);	//ra
		if (db > 0)
			steps = ft_add_step(steps, 9);	//rrb
		if (ua > 0)
			ua--;
		if (db > 0)
			db--;
		num--;
	}
	return (ft_add_step(steps, 4));	//pb
}

t_oper			*ft_da_ub(int da, int ub)
{
	t_oper		*steps;
	int			num;

	steps = NULL;
	num = da + ub;
	while (num)
	{
		if (da > 0)
			steps = ft_add_step(steps, 8);	//rra
		if (ub > 0)
			steps = ft_add_step(steps, 6);	//rb
		da--;
		ub--;
		num--;
	}
	return (ft_add_step(steps, 4));	//pb
}

int				ft_candidates(int ua, int da, int ub, int db)
{
	int			candidate[5];
	int			index;
	int			winner;

	candidate[0] = ua - ub;	//can[0] = up_a_step_num - up_b_step_num
	if (candidate[0] < 0)
		candidate[0] = -candidate[0];	//make candidate[0] positive
	candidate[1] = da - db;	//can[1] = down_a_step_num - down_b_step_num
	if (candidate[1] < 0)
		candidate[1] = -candidate[1];	//make candidate[1] positive
	candidate[2] = ua + db;	//can[2] = up_a_step_num + down_b_step_num
	candidate[3] = da + ub;	//can[3] = down_a_step_num + up_b_step_num
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
