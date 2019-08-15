
#include "libft.h"

size_t		ft_strchr_qt(const char *s, char c)
{
	size_t	quantity;

	if (s)
	{
		quantity = 0;
		while (*s)
		{
			if (*s == c)
				quantity++;
			s++;
		}
		return (quantity);
	}
	else
		return (0);
}
