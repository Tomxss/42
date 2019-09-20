/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_patterns_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:46:41 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:46:43 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_pat_precision_3(char **prec, char **new_head, char **head)
{
	*prec = ft_itoa(ft_atoi(*head));
	*new_head = ft_strdel_begn(*head, ft_strlen(*prec));
	ft_free_and_set(*&head, *&new_head);
}

static void	ft_pat_precision_2(char **prec, char **new_head, char **head)
{
	*prec = ft_strdup("*");
	*new_head = ft_strdel_begn(*head, 1);
	ft_free_and_set(*&head, *&new_head);
}

static void	ft_pat_precision_1(char **prec, char **new_head, char **head)
{
	if (ft_isdigit(*(*head + 1)) == 1)
		*prec = ft_itoa(ft_atoi(*head + 1));
	else if (*(*head + 1) == '*')
		*prec = ft_strdup("*");
	if (*prec == NULL || (*prec && **prec == '0'))
		*prec = ft_strdup("!");
	if (ft_isdigit(*(*head + 1)) == 1)
		*new_head = ft_strdel_begn(*head, ft_strlen(*prec) + 1);
	else if (*(*head + 1) == '*')
		*new_head = ft_strdel_begn(*head, 2);
	else
		*new_head = ft_strdup(*head + 1);
	ft_free_and_set(*&head, *&new_head);
}

char		*ft_pat_precision(char **head)
{
	char	*new_head;
	char	*precision;

	if (!(*head))
		return (NULL);
	precision = NULL;
	if (**head == '.')
		ft_pat_precision_1(&precision, &new_head, *&head);
	else if (**head == '*')
		ft_pat_precision_2(&precision, &new_head, *&head);
	else if (ft_isdigit(**head) == 1)
		ft_pat_precision_3(&precision, &new_head, *&head);
	return (precision);
}
