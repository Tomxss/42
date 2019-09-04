#include "push_swap.h"

static int	atoi_werror(const char *str, int *error)
{
	long long result;
	long long sign;

	sign = 1;
	result = 0;
	*error = 0;
	if (str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str == '-')
			sign = -1;
		if (*str == '-' || *str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
				result =+ result * 10 + (*str - '0');
				(*error)++;
				str++;
		}
		result = result * sign;
		if (*str < 48 && *str > 57) || result < MININT || result > MAXINT)
			return (*error = 0);
	}
	return ((int)result);
}

int ft_free_2d_array(char **array, int size)
{
	int  index;

	index = 0;
	if (!array)
		return (-1);
	while (index < size)
	{
		if (array[index])
			free(array[index]);
		index++;
	}
	free(array);
	return (-1);
}
