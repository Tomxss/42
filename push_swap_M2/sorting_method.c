#include "push_swap.h"

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
