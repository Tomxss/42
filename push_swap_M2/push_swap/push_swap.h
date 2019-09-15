/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:15:05 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/05 11:15:07 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAXINT 2147483647
# define MININT -2147483648
# include "./libft/libft/libft.h"

typedef struct s_stack
{
  int   *stack_a;
  int   a_top;
  int   a_amt_of_elems;
  int   a_buf;
  int   a_print_flag;
  int   a_max;
  int   a_mxi;
  int   a_min;
  int   a_mni;

  int   *stack_b;
  int   b_top;
  int   b_amt_of_elems;
  int   b_buf;
  int   b_print_flag;
  int   b_max;
  int   b_mxi;
  int   b_min;
  int   b_mni;

  int   size;
  int   verbose_flag;
  int   amt_of_ops;
  int   amt_of_steps;
  int   count;
  int   clear;
  char  last[4];
  int   opnum;
}             t_stack;

typedef struct s_oper
{
  char          *operations;
  int           command;
  int           num;
  struct s_oper *head;
  struct s_oper *next;
}               t_oper;

/* * * * * * * * * * * * *
* * *       PUSH_SWAP * *
* * * * * * * * * * * *
*/

int           input_error_found(int *ac, char **av, int **formatted_input, int **flags);
static char   **format_string(int *ac, char **av);
static int    find_flags(int **flags, int *flag_count, char **string, int ac);
int           free_2d_array(char **array, int size);
static int    atoi_werror(const char *str, int *error);
static int    duplicate_found(int *formatted_input, int size);
t_stack       *initiate_stacks(int *stack_a, int size, int *flag);
static void   set_stack_a(t_stack *stacks, int *stack_a, int size);
static void   set_stack_b(t_stack *stacks, int size);
static void   set_stack_ext(t_stack *stacks, int *flag, int size);
void          activate_verbose(t_stack *stacks);
static void   print_info(t_stack *stacks, int num, int *index);
static void   print_stack_a(int *a_amt_of_elems, int *a_top, t_stack *stacks, int *i);
static void   print_stack_b(int *b_amt_of_elems, int *b_top, t_stack *stacks);
static int    stack_is_empty(t_stack *stacks, char c);
int           push_swap(t_stack *stacks);
int           is_stack_in_order(t_stack *stacks);
int           isinorder(int *string, int size);
int           duo(t_stack *stacks);
int           trio(t_stack *stacks, t_oper *steps_quintet, int scene);
static t_oper *steps_for_trio(t_stack *stacks, t_oper *steps);
void          set_a_min_max(t_stack *stacks);
void          set_b_min_max(t_stack *stacks);
t_oper        *add_step(t_oper *step, int oper);
static t_oper *new_step(int oper);
static char   *get_step_name(int oper);
void          exec_free(t_stack *stacks, t_oper **results);
int           quintet(t_stack *stacks, int scene);
static t_oper	*alpha(t_oper *steps, t_stack *stacks);
static t_oper	*bravo(t_oper *steps, t_stack *stacks);
static int		a_placement(t_stack *stacks);
void          clean_a(t_stack *stacks);
static int    loop(t_stack *stacks, int i, t_oper *steps, t_oper *alt);
t_oper        *alternative_loop(t_stack *stacks);
int           up_a(t_stack *stacks, int index);
int           down_a(t_stack *stacks, int index);
static t_oper	*to_b_down(int dw_a);
static t_oper	*to_b_up(int up_a);
static t_oper	*internal_loop(t_stack *stacks, int in, int ex, int num_oper);
static t_oper	*check_steps(t_stack *stacks, int index);

/* * * * * * * * * * * * *
* * *         CHECKER * *
* * * * * * * * * * * *
*/
#endif
