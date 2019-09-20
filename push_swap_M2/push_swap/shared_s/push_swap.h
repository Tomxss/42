/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:28:08 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:28:10 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAXINT 2147483647
# define MININT -2147483648
# include "../libft/libft/libft.h"

typedef struct	s_stack
{
	int			*stack_a;
	int			a_topi;
	int			a_amt_of_elems;
	int			a_buf;
	int			print_a;
	int			a_max;
	int			a_mxi;
	int			a_min;
	int			a_mni;

	int			*stack_b;
	int			b_topi;
	int			b_amt_of_elems;
	int			b_buf;
	int			print_b;
	int			b_max;
	int			b_mxi;
	int			b_min;
	int			b_mni;

	int			size;
	int			flag;
	int			amt_of_ops;
	int			step;
	int			count;
	int			clear;
	char		last[4];
	int			opnum;


}				t_stack;

typedef struct	s_oper
{
	char			*oper;
	int				command;
	int				num;
	struct s_oper	*head;
	struct s_oper	*next;
}				t_oper;

typedef struct	s_history
{
	char				*oper;
	int					index;
	struct s_history	*first;
	struct s_history	*next;
}				t_history;

/*
** shared functions
*/
int				error_found(int *ac, char **av, int **formatted_input, int **flags);
t_stack			*initialize_stack(int *stack_a, int size, int *flag);
int				is_in_order(int *formatted_input, int size);
int				is_stack_in_order(t_stack *stacks);
void			free_all(
int				*formatted_input, t_stack *stacks, t_oper **commands, int *flags);
void			activate_verbose(t_stack *stacks);
void 			activate_help(void);
void			no_change(t_stack *stacks);
void			free_commands(t_oper **commands);
int				ft_count_words(const char *str, char c);
int				free_2d_array(char **array, int size);
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
/*
** push_swap
*/
int				duo(t_stack *stacks);
int				trio(t_stack *stacks, t_oper *steps, int scene);
int				quintet(t_stack *stacks, int scene);
int				push_swap(t_stack *stacks);
void			ft_make_b_nice(t_stack *stacks);
void			sort_a(t_stack *stacks);
t_oper			*add_step(t_oper *step, int oper);
void			free_steps(t_oper **list);
void			exec_free(t_stack *stacks, t_oper **answers);
int				candidates(int ua, int da, int ub, int db);
t_oper			*da_ub(int da, int ub);
t_oper			*ua_db(int ua, int db);
t_oper			*da_db(int da, int db);
t_oper			*ua_ub(int ua, int ub);
void			set_stack_a_min_max(t_stack *stacks);
void			set_b_min_max(t_stack *stacks);
t_oper			*alternative(t_stack *s);
int				return_up_a(t_stack *stacks, int index);
int				return_down_a(t_stack *stacks, int index);
int				return_up_b(t_stack *s, int i);
int				return_down_b(t_stack *s, int index);
int				return_up_b_helper(t_stack *stacks, int index);
int				return_down_b_helper(t_stack *stacks, int index);
void			clean_a(t_stack *stacks);
/*
** checker
*/
t_oper			*new_oper(char *str);
void			add_oper(t_oper **commands, t_oper **new);

#endif
