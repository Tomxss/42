/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:57:39 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/06/18 13:58:37 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ccpy(char **dst, char *src, char c)
{
	int	i;
	int	count;
	int	pos;

	i = -1;
	count = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[count] && count < i)
	{
		if (!(*dst = ft_strjoinchr(*dst, src[count])))
			return (0);
		count++;
	}
	return (pos);
}
