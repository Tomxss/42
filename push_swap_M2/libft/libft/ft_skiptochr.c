/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skiptochr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:00:44 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:00:47 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skiptochr(char *s, char c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == c)
				return (s - 1);
			s++;
		}
		return (s - 1);
	}
	else
		return (NULL);
}
