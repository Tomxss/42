/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 07:25:40 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/12 07:25:42 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char		*ft_strdupn(const char *s1, size_t n)
{
	char	*result;
	char	*temp;

	if (!s1)
		return (NULL);
	result = ft_strnew(n + 1);
	temp = result;
	if (result != NULL)
	{
		while (*s1 && n > 0)
		{
			*temp++ = *s1++;
			n--;
		}
		*temp = '\0';
		return (result);
	}
	else
		return (NULL);
}
