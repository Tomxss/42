void set_a_min_max(t_stack *stacks)
{
  int i;

  i = stacks->a_top;
  stacks->a_min = stacks->stack_a[i];
  stacks->a_mni = i;
  stacks->a_max = stacks->stack_a[i];
  stacks->a_mxi = i;
  while (i < stacks->size)
  {
    if (stacks->stack_a[i] < stacks->a_min)
    {
      stacks->a_min = stacks->stack_a[i];
      stacks->a_mni = i;
    }
    if (stacks->stack_b[i] > stacks->a_max)
    {
      stacks->a_max = stacks->stack_a[i];
      stacks->a_mxi = i;
    }
    i++;
  }
}
