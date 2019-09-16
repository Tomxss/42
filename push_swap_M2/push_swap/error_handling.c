/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:15:11 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/09/16 15:48:18 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	duplicate_found(int *formatted_input, int size)
{
	int num;
	int index;
	int temp;

	index = 0;
	while (index < size)
	{
		num = formatted_input[index];
		temp = index;
		while (temp < size)
		{
			if ((temp + 1) < size && formatted_input[temp + 1] == num)
				return (-1);
			temp++;
		}
		index++;
	}
	return (0);
}

static int	find_flags(int **flags, int *flag_count, char **string, int ac)
{
	int i;

	*flags = (int*)malloc(sizeof(int) * 2);
	(*flags)[0] = 0;
	(*flags)[1] = 0;
	(*flags)[2] = 0;
	(*flags)[3] = 0;
	(*flags)[4] = 0;
	*flag_count = 0;
	check_flags(&*flags, &flag_count, &*string, ac);
	i = -1;
	while (++i < 5)
		*flag_count += (*flags)[i];
	return (0);
}

static char	**format_string(int *ac, char **av)
{
	char	**string;
	int		size;
	int		index;

	if (*ac == 1)
	{
		string = ft_strsplit(av[1], ' ');
		*ac = ft_countwords(av[1], ' ');
	}
	else
	{
		size = *ac;
		string = (char**)malloc(sizeof(char*) * size);
		index = 0;
		while (index < size)
		{
			string[index] = ft_strnew(ft_strlen(av[index + 1]));
			ft_strcpy(string[index], av[index + 1]);
			index++;
		}
	}
	return (string);
}

int			input_error_found(int *ac, char **av, int **formatted_input,\
			int **flags)
{
	int			index;
	char		**string;
	long long	number;
	int			atoi_has_error;
	int			flag_count;

	index = 0;
	*ac = *ac - 1;
	string = format_string(*&ac, av);
	if (find_flags(*&flags, &flag_count, string, *ac) == -1)
		return (free_2d_array(string, *ac));
	if (!(*formatted_input = (int *)malloc(sizeof(int) * *ac)))
		return (free_2d_array(string, *ac));
	while (index < *ac - flag_count)
	{
		number = atoi_werror(string[index + flag_count], &atoi_has_error);
		if (atoi_has_error == 0)
			return (free_2d_array(string, *ac));
		(*formatted_input)[index] = (int)number;
		index++;
	}
	if (duplicate_found(*formatted_input, *ac - flag_count) == -1)
		return (free_2d_array(string, *ac));
	return (0);
}
