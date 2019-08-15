#include "libft.h"

char	*ft_ptrtoend(char *s)
{
	if (s)
	{
		while (*s)
			s++;
		return (s);
	}
	else
		return (NULL);
}
