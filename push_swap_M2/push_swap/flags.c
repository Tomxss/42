/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:45:50 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 16:02:54 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_flags(int **flags, char **string, int ac)
{
	int i;

	i = 0;
	while (i < ac && ac <= 5)
	{
		if (ft_strcmp(string[i], "-v") == 0 && (*flags)[i] == 0)
			(*flags)[i] = 1;
		else if (ft_strcmp(string[i], "-h") == 0 && (*flags)[i] == 0)
			(*flags)[i] = 1;
		else if (ft_strcmp(string[i], "-c") == 0 && (*flags)[i] == 0)
			(*flags)[i] = 1;
		else if (ft_strcmp(string[i], "-e") == 0 && (*flags)[i] == 0)
			(*flags)[i] = 1;
		else if (ft_strcmp(string[i], "-d") == 0 && (*flags)[i] == 0)
			(*flags)[i] = 1;
		i++;
	}
	return ;
}
