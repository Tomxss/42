/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 15:06:09 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/15 15:06:10 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*result;
	char	*temp;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	result = (char*)malloc(sizeof(char) * (len + 1));
	temp = result;
	if (result != NULL)
	{
		while (*s1)
			*temp++ = *s1++;
		*temp = '\0';
		return (result);
	}
	else
		return (NULL);
}
