#include "push_swap.h"

static void		upf(t_oper **copy, t_stack *stks)
{
	t_oper		*holder;

	holder = (*copy)->next;
	if (stks->flag == 0)
	{
		ft_putstr((*copy)->oper);
		ft_putchar('\n');
	}
	free((*copy)->oper);
	free((*copy));
	*copy = NULL;
	*copy = holder;
}

static int		return_brother(t_stack *s)
{
	int		index;
	int		b;
	int		a;

	index = s->a_top;
	a = s->stack_a[s->a_top];
	b = s->stack_b[s->b_top];
	while (index < s->size)
	{
		if (b < s->stack_a[index] && a > s->stack_a[index])
			return (index);
		index++;
	}
	return (-1);
}

static int		return_place(t_stack *s)
{
	int		index;
	int		b;
	int		brother;

	index = s->a_top;
	b = s->stack_b[s->b_top];
	set_min_max_a(s);
	if ((brother = return_brother(s)) != -1)
		return (brother);
	if (b > s->a_max)
		return (s->a_mni);
	if (b < s->a_min)
		return (s->a_mni);
	while (index != s->size - 1)
	{
		if (b < s->stack_a[index])
			return (index);
		else if (b > s->stack_a[index] && b < s->stack_a[index + 1]
				&& s->stack_a[index + 1] == s->size - 1)
			return (index + 1);
		else if (b > s->stack_a[index] && b < s->stack_a[index + 1])
			return (index + 1);
		index++;
	}
	return (0);
}

static void		rotate_a(t_stack *stks, int place, int up_a, int down_a)
{
	int		num;

	set_min_max_a(stks);
	up_a = up_a(stks, place);
	down_a = down_a(stks, place);
	num = down_a;
	(up_a <= down_a) ? (num = up_a) : (num);
	if (stks->a_mni != 0)
	{
		while (num--)
		{
			if (up_a < down_a)
			{
				ra(stks);
				if (stks->flag == 0)
					ft_putstr("ra\n");
			}
			else
			{
				rra(stks);
				if (stks->flag == 0)
					ft_putstr("rra\n");
			}
		}
	}
}

static int		a_placement(t_stack *stks)
{
	int			index;
	int			elem;

	index = stks->a_mni;
	elem = 4;
	if (stks->stack_b[stks->top_b] < stks->a_min)
		return (stks->a_mni);
	else if (stks->stack_b[stks->top_b] > stks->a_max)
		return (stks->a_mni);
	while ((index < stks->size))
	{
		if (stks->stack_b[stks->top_b] < stks->stack_a[index++])
			return (--index);
		elem--;
	}
	if (elem > 1)
	{
		index = stks->top_a;
		while (index != stks->a_mni)
			if (stks->stack_b[stks->top_b] < stks->stack_a[index++])
				return (--index);
	}
	return (0);
}

void			clean_a(t_stack *stacks)
{
	t_oper *steps;

	steps = NULL;
	set_min_max_a(stacks);
	if (stacks->a_mxi == stacks->a_top)
		steps = add_step(NULL, 5);
	if (stacks->elems_a == 4)
	{
		if (stacks->a_mxi == stacks->a_top + 1)
			steps = add_step(add_step(NULL, 8), 8);
		else if (stacks->a_mxi == stacks->a_top + 2)
			steps = add_step(NULL, 8);
	}
	else
	{
		if (stacks->a_mxi == stacks->a_top + 1)
			steps = add_step(add_step(NULL, 5), 5);
		else if (stacks->a_mxi == stacks->a_top + 2)
			steps = add_step(add_step(NULL, 8), 8);
		else if (stacks->a_mxi == stacks->a_top + 3)
			steps = add_step(NULL, 8);
	}
	exec_free(stacks, &steps);
}

static t_oper	*bravo(t_oper *steps, t_stack *stacks)
{
	int			place;

	place = a_placement(stacks);
	if (place == stacks->a_top)
		;
	else if (place == stacks->a_top + 1)
		steps = add_step(steps, 5);
	else if (place == stacks->a_top + 2)
		steps = add_step(add_step(steps, 5), 5);
	else if (place == stacks->a_top + 3)
		steps = add_step(steps, 8);
	return (add_step(steps, 3));
}

static t_oper	*alpha(t_oper *steps, t_stack *stacks)
{
	set_a_min_max(stacks);
	if (s->stack_b[stacks->b_top] < stacks->a_min)
		steps = add_step(steps, 3);
	else if (s->stack_b[stacks->b_top] > stacks->a_max)
		steps = add_step(steps, 3);
	else if (s->stack_b[stacks->b_top] < stacks->stack_a[s->a_top + 1])
		steps = add_step(add_step(steps, 5), 3);
	else if (s->stack_b[stacks->b_top] > stacks->stack_a[s->a_top + 1])
		steps = add_step(add_step(steps, 8), 3);
	return (steps);
}

static char   *get_step_name(int oper)
{
  if (oper == 0)
    return (ft_strdup("sa"));
  else if (oper == 1)
    return (ft_strdup("sb"));
  else if (oper == 2)
    return (ft_strdup("ss"));
  else if (oper == 3)
    return (ft_strdup("pa"));
  else if (oper == 4)
    return (ft_strdup("pb"));
  else if (oper == 5)
    return (ft_strdup("ra"));
  else if (oper == 6)
    return (ft_strdup("rb"));
  else if (oper == 7)
    return (ft_strdup("rr"));
  else if (oper == 8)
    return (ft_strdup("rra"));
  else if (oper == 9)
    return (ft_strdup("rrb"));
  else if (oper == 10)
    return (ft_Strdup("rrr"));
  else
    return (NULL);
  }

static t_oper *new_step(int oper)
{
  t_oper  *new;

  new = (t_oper*)malloc(sizeof(t_oper) * 1);
  if (!new)
    return (NULL);
  new->oper = get_step_name(oper);
  if(!new->oper)
  {
    free(new);
    return (NULL);
  }
  new->command = oper;
  new->num = 1;
  new->head = NULL;
  new->next = NULL;
  return (new);
}

t_oper        *add_step(t_oper *step, int oper)
{
  t_oper *new;

  if (!(new = new_step(oper)))
    return (NULL);
  if (step)
  {
    step->next = new;
    new->head = step->head;
    step->head->num = ++(step->head->num);
    step = new;
  }
  else
    new->head = new;
    step = new;
}
return (step);

static t_oper *steps_for_trio(t_stack *stacks, t_oper *steps)
{
  set_a_min_max(stacks);
  if (stacks->a_mxi == stacks->a_top + 1 && stacks->a_mni == stacks->a_top)
    steps = add_step(add_step(steps, 8), 0);
  else if (stacks->a_mxi == stacks->a_top && stacks->a_mni == stacks->a_top + 2)
    steps = add_step(add_step(steps, 5), 0);
  else if (stacks->a_mxi == stacks->a_top && stacks->a_mni == stacks->a_top + 1)
    steps = add_step(steps, 5);
  else if (stacks->a_mxi == stacks->a_top + 2 && stacks->a_mni == stacks->a_top + 1)
    steps = add_step(steps, 0);
  else if (stacks->a_mxi == stacks->a_top + 1 && stacks->a_mni == stacks->a_top + 2)
    steps = add_step(steps, 8);
  return (steps);
}
