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

int				main(int argc, char **argv)
{
	int			*tab;
	int			*flags;
	t_stack		*stks;

	if (argc <= 1)
		return (0);
	tab = NULL;
	stks = NULL;
	if (ft_validator(&argc, argv, &tab, &flags) == -1)
		ft_putstr_fd("Error\n", 2);
	else
	{
		if (!(stks = ft_new_stks(*&tab, argc - flags[0] - flags[1], flags)))
			ft_putstr_fd("Error\n", 2);
		else if (ft_push_swap(*&stks) == -1)
			ft_putstr_fd("Error\n", 2);
	}
	ft_free_all(tab, stks, NULL, flags);
	return (0);
}
