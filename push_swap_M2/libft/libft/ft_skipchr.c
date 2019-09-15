/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:41:32 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:41:36 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_skipchr(char *s, char c)
{
	if (s)
	{
		while (*(unsigned char*)s == (unsigned char)c)
			s++;
		return ((char*)s);
	}
	else
		return (NULL);
}
