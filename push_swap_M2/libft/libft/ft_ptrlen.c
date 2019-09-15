/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:43:41 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:43:49 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_ptrlen(char *beg, char *end)
{
	size_t		len;

	if (beg && end)
	{
		len = 0;
		while (beg++ != end)
			len++;
		return (len + 1);
	}
	else
		return (1);
}
