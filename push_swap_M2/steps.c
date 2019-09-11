#include "push_swap.h"

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
