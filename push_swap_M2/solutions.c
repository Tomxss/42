
int				down_b_helper(t_stack *stks, int index)
{
	return (stks->size - index);
}

static void		check_after_max_b(t_stack *s, int *win, int *elem, int index)
{
	int			b_max_index;

	*elem = 0;
	b_max_index = s->b_mxi;
	while (b_max_index < s->size)
	{
		if (s->stack_a[index] > s->stack_b[b_max_index])
		{
			*win = b_max_index;
			(*elem) = s->b_amt_of_elems;
			break ;
		}
		b_max_index++;
		(*elem)++;
	}
}

static void		check_before_max_b(t_stack *s, int *win, int index)
{
	int			b_max_index;
	int			top_b;

	b_max_index = s->b_mxi;
	top_b = s->top_b;
	while (top_b != b_max_index)
	{
		if (s->stack_a[index] > s->stack_b[top_b])
		{
			*win = top_b;
			break ;
		}
		top_b++;
	}
}

int				down_b(t_stack *s, int index)
{
	int			steps;
	int			elem;
	int			winner;

	if (s->stack_a[index] > s->b_max)
		steps = down_b_helper(s, s->b_mxi);
	else if (s->stack_a[index] < s->b_min)
		steps = down_b_helper(s, s->b_mxi);
	else
	{
		check_after_max_b(s, &winner, &elem, index);
		if (elem < s->b_amt_of_elems)
			check_before_max_b(s, &winner, index);
		steps = down_b_helper(s, winner);
	}
	return (steps);
}

int				up_b_helper(t_stack *stks, int index)
{
	int			num;

	if (index == stks->top_b)
		return (0);
	num = stks->top_b - index;
	if (num < 0)
		num = -1 * num;
	return (num);
}

static void		check_after_max_b(t_stack *s, int *win, int *elem, int index)
{
	int			b_max_index;

	*elem = 0;
	b_max_index = s->b_mxi;
	while (b_max_index < s->size)
	{
		if (s->stack_a[index] > s->stack_b[b_max_index])
		{
			*win = b_max_index;
			(*elem) = s->b_amt_of_elems;
			break ;
		}
		b_max_index++;
		(*elem)++;
	}
}

static void		check_before_max_b(t_stack *s, int *win, int index)
{
	int			b_max_index;
	int			top_b;

	b_max_index = s->b_mxi;
	top_b = s->top_b;
	while (top_b != b_max_index)
	{
		if (s->stack_a[index] > s->stack_b[top_b])
		{
			*win = top_b;
			break ;
		}
		top_b++;
	}
}

int				up_b(t_stack *s, int index)
{
	int			steps;
	int			elem;
	int			winner;

	if (s->stack_a[index] > s->b_max)
		steps = up_b_helper(s, s->b_mxi);
	else if (s->stack_a[index] < s->b_min)
		steps = up_b_helper(s, s->b_mxi);
	else
	{
		check_after_max_b(s, &winner, &elem, index);
		if (elem < s->b_amt_of_elems)
			check_before_max_b(s, &winner, index);
		steps = up_b_helper(s, winner);
	}
	return (steps);
}

int				up_a(t_stack *stacks, int index)
{
	int			num;

	if (index == stacks->top_a)
		return (0);
	num = stacks->top_a - index;
	if (num < 0)
		num = -1 * num;
	return (num);
}

int				down_a(t_stack *stacks, int index)
{
	if (index == stacks->size - 1 && stacks->a_amt_of_elems == 1)
		return (0);
	return (stacks->size - index);
}

static t_oper		*to_b_up(int up_a)
{
	t_oper			*steps;

	steps = NULL;
	while (up_a > 0)
	{
		steps = add_step(steps, 5);
		up_a--;
	}
	steps = add_step(steps, 4);
	return (steps);
}

static t_oper		*to_b_down(int dw_a)
{
	t_oper			*steps;

	steps = NULL;
	while (dw_a > 0)
	{
		steps = add_step(steps, 8);
		dw_a--;
	}
	steps = add_step(steps, 4);
	return (steps);
}
