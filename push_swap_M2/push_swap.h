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
