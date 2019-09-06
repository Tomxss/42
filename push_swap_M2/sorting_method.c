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
