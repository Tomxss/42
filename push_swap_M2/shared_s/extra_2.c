/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:40:06 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/20 12:44:28 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_dup_flags(char **av, int ac)
{
	if (ac > 2)
	{
		if (ft_strcmp(av[0], "-v") == 0 && ft_strcmp(av[1], "-v") == 0)
			return (-1);
		if (ft_strcmp(av[0], "-vc") == 0 && ft_strcmp(av[1], "-vc") == 0)
			return (-1);
		if (ft_strcmp(av[0], "-vc") == 0 && ft_strcmp(av[1], "-v") == 0)
			return (-1);
		if (ft_strcmp(av[0], "-h") == 0 && ft_strcmp(av[1], "-h") == 0)
			return (-1);
	}
}

int		free_2d_array(char **array, int size)
{
	int			index;

	index = 0;
	if (!array)
		return (-1);
	while (index < size)
	{
		if (array[index])
			free(array[index]);
		index++;
	}
	free(array);
	return (-1);
}
