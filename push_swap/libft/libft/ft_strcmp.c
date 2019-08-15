/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:31:16 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/06/06 13:47:21 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t i;

	i = 0;
	while ((str1[i] != '\0') || (str2[i] != '\0'))
	{
		if ((unsigned char)str1[i] > (unsigned char)str2[i])
			return (1);
		if ((unsigned char)str1[i] < (unsigned char)str2[i])
			return (-1);
		i++;
	}
	return (0);
}
