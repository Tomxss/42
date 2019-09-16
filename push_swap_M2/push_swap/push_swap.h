/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:15:05 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 16:20:24 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAXINT 2147483647
# define MININT -2147483648
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft/libft.h"

typedef struct	s_stack
{
	int			*stack_a;
	int			a_top;
	int			a_amt_of_elems;
	int			a_buf;
	int			a_print_flag;
	int			a_max;
	int			a_mxi;
	int			a_min;
	int			a_mni;

	int			*stack_b;
	int			b_top;
	int			b_amt_of_elems;
	int			b_buf;
	int			b_print_flag;
	int			b_max;
	int			b_mxi;
	int			b_min;
	int			b_mni;

	int			size;
	int			verbose_flag;
	int			amt_of_ops;
	int			amt_of_steps;
	int			count_flag;
	int			clear;
	char		last[4];
	int			opnum;
}				t_stack;

typedef struct	s_oper
{
	char			*operations;
	int				command;
	int				num;
	struct s_oper	*head;
	struct s_oper	*next;
}				t_oper;

/*
** PUSH_SWAP
*/

int				input_error_found(int *ac, char **av, int **formatted_input,\
				int **flags);
int				atoi_werror(const char *str, int *error);
int				free_2d_array(char **array, int size);
t_stack			*initiate_stacks(int *stack_a, int size, int *flag);
void			activate_verbose(t_stack *stacks);
int				push_swap(t_stack *stacks);
int				is_stack_in_order(t_stack *stacks);
int				isinorder(int *string, int size);
int				return_place(t_stack *s);
int				duo(t_stack *stacks);
int				trio(t_stack *stacks, t_oper *steps_quintet, int scene);
void			set_a_min_max(t_stack *stacks);
void			set_b_min_max(t_stack *stacks);
t_oper			*add_step(t_oper *step, int oper);
void			exec_free(t_stack *stacks, t_oper **results);
int				quintet(t_stack *stacks, int scene);
void			clean_a(t_stack *stacks);
t_oper			*alternative_loop(t_stack *stacks);
void			rotate_a(t_stack *stacks, int place, int up_a, int down_a);
t_oper			*to_b_up(int up_a);
t_oper			*to_b_down(int dw_a);
int				return_up_a(t_stack *stacks, int index);
int				return_up_b(t_stack *s, int index);
int				return_down_a(t_stack *stacks, int index);
int				return_down_b(t_stack *s, int index);
t_oper			*alpha(t_oper *steps, t_stack *stacks);
t_oper			*bravo(t_oper *steps, t_stack *stacks);
t_oper			*steps_for_trio(t_stack *stacks, t_oper *steps);
void			free_all(int *formatted_input, t_stack *stacks,\
				t_oper **commands, int *flags);

/*
** SHARED
*/

void			sa(t_stack *stacks);
void			sb(t_stack *stacks);
void			ss(t_stack *stacks);
void			pa(t_stack *stacks);
void			pb(t_stack *stacks);
void			ra(t_stack *stacks);
void			rb(t_stack *stacks);
void			rr(t_stack *stacks);
void			rra(t_stack *stacks);
void			rrb(t_stack *stacks);
void			rrr(t_stack *stacks);
void			no_change(t_stack *stacks);

#endif
