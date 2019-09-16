/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipspace_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:37:10 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:44:53 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_skipspace_end(char *s)
{
	unsigned int	len;

	if (s)
	{
		len = ft_strlen(s);
		if (len == 0)
			return (s);
		s = s + (len - 1);
		while ((*s == ' ' || *s == '\n' || *s == '\t') && len-- > 0)
			s--;
		return (s);
	}
	else
		return (NULL);
}
