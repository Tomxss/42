/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:27:43 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/23 11:27:44 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static int		atoi_werror(const char *str, int *error)
{
	long long	result;
	long long	sign;

	sign = 1;
	result = 0;
	*error = 0;
	if (str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str == '-')
			sign = -1;
		if (*str == '+' || *str == '-')
			str++;
		while (ft_isdigit(*str))
		{
			result = 10 * result + (*str - '0');
			(*error)++;
			str++;
		}
		result = result * sign;
		if ((*str >= 1 && *str <= 127) || result < MININT || result > MAXINT)
			return (*error = 0);
	}
	return ((int)result);
}

static int		is_duplicates(int *formatted_input, int size)
{
	int			number;
	int			index1;
	int			index2;

	index1 = 0;
	number = formatted_input[index1];
	while (index1 < size)
	{
		number = formatted_input[index1];
		index2 = index1;
		while (index2 < size)
		{
			if ((index2 + 1) < size)
			{
				if (formatted_input[index2 + 1] == number)
					return (-1);
			}
			index2++;
		}
		index1++;
	}
	return (0);
}

static int		check_flags(int **flags, int *flag, char **av, int ac)
{
	*flags = (int*)malloc(sizeof(int) * 3);
	(*flags)[0] = 0;
	(*flags)[1] = 0;
	(*flags)[2] = 0;
	*flag = 0;
	if (ac > 2)
	{
		if (ft_strcmp(av[0], "-v") == 0 && ft_strcmp(av[1], "-v") == 0)
			return (-1);
		if (ft_strcmp(av[0], "-vc") == 0 && ft_strcmp(av[1], "-vc") == 0)
			return (-1);
		if (ft_strcmp(av[0], "-vc") == 0 && ft_strcmp(av[1], "-v") == 0)
			return (-1);
		if (ft_strcmp(av[0], "-h") == 0 && ft_strcmp(av[1], "-h") == 0)
			return (-1);
	}
	if (ft_strcmp(av[0], "-v") == 0)
		(*flags)[0] = 1;
	if (ft_strcmp(av[0], "-vc") == 0)
	{
		(*flags)[1] = 1;
		(*flags)[0] = 1;
	}
	if (ft_strcmp(av[0], "-h") == 0)
		(*flags)[2] = 1;

	*flag = *(flags)[0] + (*flags)[2];
	return (0);
}

static char		**return_string(int *ac, char **av)
{
	char		**string;
	int			size;
	int			index;

	if (*ac == 1)
	{
		string = ft_strsplit(av[1], ' ');
		*ac = ft_count_words(av[1], ' ');
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

int				error_found(int *ac, char **av, int **formatted_input, int **flags)
{
	int			index;
	char		**string;
	long long	number;
	int			atoi_error;
	int			flag;

	index = 0;
	*ac = *ac - 1;
	string = return_string(*&ac, av);
	if (check_flags(*&flags, &flag, string, *ac) == -1)
		return (free_2d_array(string, *ac));
	if (!(*formatted_input = (int*)malloc(sizeof(int) * *ac)))
		return (free_2d_array(string, *ac));
	while (index < *ac - flag)
	{
		number = atoi_werror(string[index + flag], &atoi_error);
		if (number < MININT || number > MAXINT || atoi_error == 0)
			return (free_2d_array(string, *ac));
		(*formatted_input)[index] = (int)number;
		index++;
	}
	if ((is_duplicates(*formatted_input, *ac - flag)) == -1)
		return (free_2d_array(string, *ac));
	return (0);
}
