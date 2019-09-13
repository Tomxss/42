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
	return (ft_add_step(steps, 4));	//pb
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
	return (ft_add_step(steps, 4));	//pb
}

int				candidates(int ua, int da, int ub, int db)
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
	set_a_min_max_(stacks);
	rotate_a(stacks, stacks->a_mni, 0, 0);
}
/* * * * *
* * * * *	EVERYTHING TO DO WITH STEPS
*/

static t_oper	*check_steps(t_stack *stacks, int index)
{
	int			up_a;
	int			up_b;
	int			down_a;
	int			down_b;
	int			winner;

	set_b_min_max(stacks);
	up_a = up_a(stacks, index);
	down_a = down_a(stacks, index);
	up_b = up_b(stacks, index);
	down_b = down_b(stacks, index);
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
		free(temp->oper);
		free(temp);
		temp = head;
	}
	*list = NULL;
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
t_oper				*alternative_loop(t_stack *stacks)
{
	int				a_top;
	int				ntopb;
	int				up_a;
	int				dw_a;

	ntopb = stacks->stack_b[s->b_top];
	a_top = stacks->a_top;
	while (a_top != stacks->size - 1)
	{
		if (stacks->stack_a[a_top] > ntopb && stacks->stack_a[a_top] < stacks->stack_b[stacks->size - 1])
		{
			up_a = up_a(stacks, a_top);
			dw_a = down_a(stacks, a_top);
			if (up_a > dw_a)
				return (to_b_down(dw_a));
			else
				return (to_b_up(up_a));
		}
		a_top++;
	}
	return (NULL);
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
			alt = alternative_loop(stacks);
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
		if (stacks->elems_a == 5)
			break ;
	}
	finalize_stacks(stacks);
	return (1);
}

int quintet(t_stack *stacks, int scene)
{
  t_oper  *steps;

  steps = add_step(NULL, 4);
  if (stacks->a_amt_of_elems == 5 || stacks->size == 5)
    steps = add_step(steps, 4);
  trio(stacks, steps, scene);
  steps = alpha(NULL, stacks);
  exec_free(stacks, &steps);
  if (stacks->size == 5 || stacks->a_amt_of_elems == 5 || scene == 3)
  {
    set_a_min_max(stacks);
    steps = bravo(NULL, stacks);
    exec_free(stacks, &steps);
  }
  clean_a(stacks);
  return (1);
}

int trio(t_stack *stacks, t_oper *steps_quintet, int scene)
{
  t_oper *steps;

  steps = NULL;
  if (scene == 1)
  {
    steps = steps_for_trio(stacks, steps);
    exec_free(stacks, &steps);
  }
  else if (scene == 2)
  {
    (stacks->size == 4) ? (stacks->a_top = 1) : (0);
    (stacks->size == 5) ? (stacks->a_top = 2) : (0);
    (steps_quintet) ? (steps = steps_quintet) : (0);
    steps = steps_for_trio(stacks, steps);
    stacks->a_top = 0;
    exec_free(stacks, &steps);
  }
  else if (scene == 3)
  {
    exec_free(stacks, &steps_quintet);
    steps = steps_for_trio(stacks, &steps);
    exec_free(stacks, &steps);
  }
  return (1);
}

int duo(t_stack *stacks)
{
  sa(stacks);
  ft_putstr("sa\n");
  return (1);
}

int push_swap(t_stack *stacks)
{
  if (is_stack_in_order(stacks) == 1)
    return (1);
  else if (stacks->size == 2)
    return (duo(stacks));
  else if (stacks->size == 3)
    return (trio(stacks));
  else if (stacks->size == 5)
    return (quintet(stacks));
  else if (loop(*&stacks, 0, NULL, NULL) == -1)
    return (-1);
  else
    return (1);
}
