
#include "libft.h"

char	*ft_skiptochr(char *s, char c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == c)
				return (s - 1);
			s++;
		}
		return (s - 1);
	}
	else
		return (NULL);
}
