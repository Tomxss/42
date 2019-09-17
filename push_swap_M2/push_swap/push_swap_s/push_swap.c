/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:25:13 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:25:16 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
** PUSH_SWAP
*/

int				main(int ac, char **av)
{
	int			*formatted_input;
	int			*flags;
	t_stack		*stacks;

	if (ac <= 1)
		return (0);
	formatted_input = NULL;
	stacks = NULL;
	if (error_found(&ac, av, &formatted_input, &flags) == -1)
		ft_putstr_fd("Error\n", 2);
	else
	{
		if (!(stacks = initialize_stack(*&formatted_input, ac - flags[0] - flags[1], flags)))
			ft_putstr_fd("Error\n", 2);
		else if (push_swap(*&stacks) == -1)
			ft_putstr_fd("Error\n", 2);
	}
	free_all(formatted_input, stacks, NULL, flags);
	return (0);
}
