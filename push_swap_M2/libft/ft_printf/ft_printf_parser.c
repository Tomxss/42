/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:46:20 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:46:22 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_get_no_modifier(char **str, size_t *len, int *scob, int *beg)
{
	(*len) += (*beg);
	*str = (*str + *beg);
	if (**str == '%')
	{
		(*len)++;
		(*str)++;
	}
	if ((*scob) > 0)
	{
		(*len) -= 1;
		--(*str);
	}
}

static void	ft_get_true_percent(char **str, size_t *len)
{
	int		counter;
	int		beg;
	int		scob;

	counter = 0;
	beg = 0;
	scob = 0;
	while ((*(*str + beg) != '\0') && *(*str + beg) != '%')
	{
		if (ft_is_modifier(*(*str + beg)) == 1)
			counter++;
		if (*(*str + beg) == '}')
			scob++;
		beg++;
	}
	if (counter == 0)
		ft_get_no_modifier(*&str, *&len, &scob, &beg);
	else
		while (**str != '%' && **str != '\0')
		{
			(*len)++;
			(*str)++;
			if (**str == '}')
				break ;
		}
}

static void	ft_get_arg(char **str, size_t *beg, size_t *yn, size_t *len)
{
	*yn = 0;
	*len = 0;
	if (**str == '{')
	{
		(*len)++;
		(*str)++;
		return ;
	}
	if (**str == '%')
	{
		(*yn)++;
		(*str)++;
		ft_get_true_percent(*&str, *&len);
	}
	else
		while (**str != '%' && **str != '\0')
		{
			(*len)++;
			(*str)++;
			if (**str == '}')
				break ;
		}
	if (*yn > 0)
		(*beg)++;
}

static void	ft_check_patterns(
			t_com **com, size_t *yn, char **head)
{
	char	*copy;
	t_com	*fresh;

	fresh = ft_tcom_new();
	if (ft_pat_one(*&com, &fresh, *&head, *&yn) == 1)
		return ;
	copy = ft_strdup(*head);
	(fresh)->param = ft_pat_parameter(*&head);
	(fresh)->flag = ft_pat_flags(*&head);
	(fresh)->width = ft_pat_width(*&head);
	(fresh)->precision = ft_pat_precision(*&head);
	(fresh)->length = ft_pat_length(*&head);
	(fresh)->modifier = ft_pat_modifier(*&head);
	ft_pat_ending(&fresh, *&head);
	ft_tcom_list(*&com, fresh);
	if (*head == NULL)
		return (free(copy));
	else
		ft_pat_string(*&com, &copy, *&head);
}

void		ft_parser(const char *format, t_com **com)
{
	char	*copy;
	char	*head;
	size_t	beg;
	size_t	yn;
	size_t	len;

	*com = NULL;
	beg = 0;
	copy = (char*)format;
	while (*copy != '\0')
	{
		ft_get_arg(&copy, &beg, &yn, &len);
		if (*copy == '\0' && len == 0)
			break ;
		ft_memnncpy((head = ft_strnew(len + 1)), format, beg, len);
		beg += len;
		ft_check_patterns(*&com, &yn, &head);
	}
	ft_tcom_revert(*&com);
}
