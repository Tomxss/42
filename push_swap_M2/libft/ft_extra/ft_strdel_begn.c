/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_begn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 07:25:19 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/12 07:25:21 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char				*ft_strdel_begn(char *str, size_t n)
{
	char			*result;
	size_t			len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (n > len)
		return (NULL);
	if (!(result = ft_strnew(len - n + 2)))
		return (NULL);
	ft_memnncpy(result, str, n, (len - n));
	return (result);
}
