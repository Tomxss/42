/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_qt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:42:49 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:42:54 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strchr_qt(const char *s, char c)
{
	size_t	quantity;

	if (s)
	{
		quantity = 0;
		while (*s)
		{
			if (*s == c)
				quantity++;
			s++;
		}
		return (quantity);
	}
	else
		return (0);
}
