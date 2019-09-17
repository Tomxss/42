#include "push_swap.h"

t_oper			*ua_ub(int ua, int ub)
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
			steps = add_step(steps, 7);	//rr
		}
		else
		{
			if (ua > 0)
				steps = add_step(steps, 5);	//ra
			if (ub > 0)
				steps = add_step(steps, 6);	//rb
		}
		ua--;
		ub--;
	}
	return (add_step(steps, 4));	//pb
}

t_oper			*da_db(int da, int db)
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
			steps = add_step(steps, 10);	//rrr
		else
		{
			if (da > 0)//only down_a is positive
				steps = add_step(steps, 8);	//rra
			if (db > 0)//only down_b is positive
				steps = add_step(steps, 9);	//rrb
		}
		if (da > 0)
			da--;
		if (db > 0)
			db--;
	}
	return (add_step(steps, 4));	//pb
}

t_oper			*ua_db(int ua, int db)
{
	t_oper		*steps;
	int			num;

	steps = NULL;
	num = ua + db;
	while (num)
	{
		if (ua > 0)
			steps = add_step(steps, 5);	//ra
		if (db > 0)
			steps = add_step(steps, 9);	//rrb
		if (ua > 0)
			ua--;
		if (db > 0)
			db--;
		num--;
	}
	return (add_step(steps, 4));	//pb
}

t_oper			*da_ub(int da, int ub)
{
	t_oper		*steps;
	int			num;

	steps = NULL;
	num = da + ub;
	while (num)
	{
		if (da > 0)
			steps = add_step(steps, 8);	//rra
		if (ub > 0)
			steps = add_step(steps, 6);	//rb
		da--;
		ub--;
		num--;
	}
	return (add_step(steps, 4));	//pb
}