/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_patterns_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:46:33 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:46:36 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_pat_length(char **head)
{
	char	*result;
	char	*new_head;
	size_t	len;

	if (ft_is_length(**head) == 0)
		return (NULL);
	len = 1;
	if (*(*head + 1) == 'h' || *(*head + 1) == 'l')
		len = 2;
	result = ft_strnew(len + 1);
	ft_memcpy(result, *head, len);
	new_head = ft_strdel_begn(*head, len);
	ft_free_and_set(*&head, &new_head);
	return (result);
}

char		*ft_pat_modifier(char **head)
{
	char	*modifier;
	char	*new_head;

	if (!(*head) || ft_is_modifier(**head) == 0)
		return (NULL);
	if (ft_strlen(*head) == 1)
	{
		modifier = ft_strdup(*head);
		free(*head);
		*head = NULL;
		return (modifier);
	}
	modifier = ft_strnew(2);
	ft_memcpy(modifier, *head, 1);
	new_head = ft_strdel_begn(*head, 1);
	ft_free_and_set(*&head, &new_head);
	return (modifier);
}

void		ft_pat_ending(t_com **fresh, char **head)
{
	if ((*fresh)->modifier == NULL && *head)
	{
		(*fresh)->scroll = ft_strdup(*head);
		(*fresh)->len = ft_strlen((*fresh)->scroll);
		free(*head);
		*head = NULL;
	}
	else
		(*fresh)->type = '%';
}

void		ft_pat_string(t_com **com, char **copy, char **head)
{
	t_com	*fresh;

	if (ft_strcmp(*copy, *head) != 0)
	{
		fresh = ft_tcom_new();
		fresh->scroll = *head;
		fresh->len = ft_strlen(*head);
		ft_tcom_list(*&com, fresh);
		free(*copy);
	}
}
