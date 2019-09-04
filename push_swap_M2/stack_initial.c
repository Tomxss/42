#include "push_swap.h"

static void set_stack_a(t_stack *stacks, int *stack_a, int size)
{
  stacks->stack_a = stack_a;
  stacks->top_a = 0;
  stacks->elems_a = size;
  stacks->a_max = 0;
  stacks->a_min = 0;
  stacks->a_mxi = 0;
  stacks->a_mni = 0;
}

t_stack *initiate_stacks(int *stack_a, int size, int *flag)
{
  t_stack *stacks;

  if (!(stacks = (t_stack*)malloc(sizeof(t_stack) * 1)))
    return (NULL);
  set_stack_a(stacks, stack_a, size);
  set_stack_b(stacks, size);
  if (!stacks->stack_b)
  {
    free(stacks);
    return (NULL);
  }
}
