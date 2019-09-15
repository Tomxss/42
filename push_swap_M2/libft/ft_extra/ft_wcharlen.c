/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 07:24:56 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/12 07:24:59 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

size_t		ft_wcharlen(wchar_t wchar)
{
	size_t	length;

	length = 0;
	if (wchar < (1 << 7))
		length = 1;
	else if (wchar < (1 << 11))
		length = 2;
	else if (wchar < (1 << 16))
		length = 3;
	else if (wchar < (1 << 21))
		length = 4;
	return (length);
}
