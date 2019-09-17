/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 07:24:41 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/12 07:24:48 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void		*ft_memnncpy(void *dst, const void *src, size_t start, size_t n)
{
	size_t	i;

	i = 0;
	while (i < start && *(unsigned char*)src != '\0')
	{
		src++;
		i++;
	}
	return (ft_memcpy(dst, src, n));
}
