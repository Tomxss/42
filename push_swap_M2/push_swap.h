#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAXINT 2147483647
# define MININT -2147483648
# include "./libft/libft/libft.h"

typedef struct s_stack
{
  int *stack_a;
  int a_top;
  int a_amount_of_elems;
  int size;
  int flag;
  int operations;

}
