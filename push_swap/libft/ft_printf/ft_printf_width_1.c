/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:47:30 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:47:31 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** pre print width
*/

void			ft_pre_print_width(t_com **com)
{
	intmax_t	width;
	size_t		len;
	size_t		new_width;
	char		*spaces;
	char		*result;

	if ((*com)->width)
	{
		width = ft_atoi((*com)->width);
		if (width < 0)
		{
			new_width = (size_t)-width;
			len = (*com)->len;
			spaces = ft_strnew_char_filled(new_width - len, ' ');
			result = ft_strjoin((*com)->scroll, spaces);
			free((*com)->scroll);
			free(spaces);
			(*com)->scroll = result;
			if (new_width > len)
				(*com)->len = (size_t)new_width;
		}
		else
			ft_mod_add_spaces(*&com);
	}
}
