/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:26:29 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:26:31 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_free_2d_array(char **array, int size)
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
