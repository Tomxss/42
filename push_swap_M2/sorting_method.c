#include "push_swap.h"

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
		if (stacks->stk_a[a_top] > ntopb && stacks->stk_a[a_top] < stacks->stack_b[stacks->size - 1])
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
