/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:46:58 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:47:00 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ******* pre print null precision *******************************************
*/

static void		ft_pre_print_null_precision_helper(t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	if (*(*com)->modifier == 'p')
	{
		(*com)->scroll = ft_strdup("0x");
		(*com)->len = 2;
	}
	else if (*(*com)->modifier == 'S')
	{
		(*com)->scroll = ft_strdup("");
		(*com)->len = 0;
		*(*com)->modifier = 's';
	}
	else
	{
		(*com)->scroll = ft_strdup("");
		(*com)->len = 0;
	}
	free((*com)->precision);
	(*com)->precision = NULL;
}

void			ft_pre_print_null_precision(t_com **com)
{
	char		*mod;

	if ((*com)->precision && *(*com)->precision == '!' &&
		(((*com)->scroll && *(*com)->scroll == '0') ||
		((*com)->modifier &&
		(*(*com)->modifier == 's' || *(*com)->modifier == 'S'))))
	{
		if (!(mod = (*com)->modifier))
			return ;
		if (*mod == 's' || *mod == 'S' || *mod == 'i'
			|| *mod == 'd' || *mod == 'D' || *mod == 'u' || *mod == 'U')
			ft_pre_print_null_precision_helper(*&com);
		else if ((*mod == 'x' || *mod == 'X')
				&& ft_strchr_qt((*com)->flag, '#') > 0)
			ft_pre_print_null_precision_helper(*&com);
		else if (*mod == 'x' || *mod == 'X')
			ft_pre_print_null_precision_helper(*&com);
		else if ((*mod == 'o' || *mod == 'O')
				&& ft_strchr_qt((*com)->flag, '#') == 0)
			ft_pre_print_null_precision_helper(*&com);
		else if ((*mod == 'p' || *(*com)->modifier == 'P')
				&& (*com)->len == 3)
			ft_pre_print_null_precision_helper(*&com);
	}
}
