/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_patterns_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:46:27 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:46:29 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_pat_one(t_com **com, t_com **fresh, char **head, size_t *yn)
{
	if (*yn == 0)
	{
		(*fresh)->scroll = *head;
		(*fresh)->len = ft_strlen(*head);
		ft_tcom_list(*&com, *fresh);
		return (1);
	}
	return (0);
}

char		*ft_pat_parameter(char **head)
{
	char	*copy;
	char	*parameter;
	char	*new_head;
	size_t	len;

	if (!(*head))
		return (NULL);
	len = 0;
	copy = *head;
	while (ft_isdigit(*copy) == 1)
	{
		len++;
		copy++;
	}
	if (len > 0 && *copy == '$')
	{
		parameter = ft_strnew(len + 1);
		ft_memcpy(parameter, *head, len);
		new_head = ft_strdel_begn(*head, len + 1);
		ft_free_and_set(*&head, &new_head);
		return (parameter);
	}
	return (NULL);
}

static void	ft_pat_flags_parser(char **flag)
{
	char	*flag_copy;
	char	*result;
	char	*result_copy;
	char	*formatted_input;

	flag_copy = *flag;
	result = ft_strnew(5 + 1);
	result_copy = result;
	formatted_input = ft_strnew_char_filled(5, 0);
	while (*flag_copy)
	{
		if (*flag_copy == '-' && (formatted_input[0]++ < 1))
			*result_copy++ = *flag_copy;
		if (*flag_copy == '+' && (formatted_input[1]++ < 1))
			*result_copy++ = *flag_copy;
		if (*flag_copy == ' ' && (formatted_input[2]++ < 1))
			*result_copy++ = *flag_copy;
		if (*flag_copy == '0' && (formatted_input[3]++ < 1))
			*result_copy++ = *flag_copy;
		if (*flag_copy == '#' && (formatted_input[4]++ < 1))
			*result_copy++ = *flag_copy;
		flag_copy++;
	}
	ft_free_and_set(*&flag, &result);
	free(formatted_input);
}

char		*ft_pat_flags(char **head)
{
	char	*new_head;
	char	*flag;
	char	*copy;
	size_t	len;

	if (!(*head) || ft_is_flag(**head) == 0)
		return (NULL);
	flag = NULL;
	copy = *head;
	len = 0;
	while (ft_is_flag(*copy) == 1)
	{
		copy++;
		len++;
	}
	flag = ft_strdupn(*head, len);
	new_head = ft_strdel_begn(*head, len);
	ft_free_and_set(*&head, &new_head);
	if (flag != NULL)
		ft_pat_flags_parser(&flag);
	return (flag);
}

char		*ft_pat_width(char **head)
{
	char	*new_head;
	char	*width;
	char	*copy;

	if (!(*head))
		return (0);
	copy = *head;
	if (*copy == '*')
	{
		width = ft_strdup("*");
		new_head = ft_strdel_begn(*head, 1);
		ft_free_and_set(*&head, &new_head);
		return (width);
	}
	if (ft_isdigit(*copy) == 1)
	{
		width = ft_itoa(ft_atoi(*head));
		new_head = ft_strdel_begn(*head, ft_strlen(width));
		ft_free_and_set(*&head, &new_head);
		return (width);
	}
	return (NULL);
}
