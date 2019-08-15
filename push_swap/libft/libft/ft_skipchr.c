
#include "libft.h"

char		*ft_skipchr(char *s, char c)
{
	if (s)
	{
		while (*(unsigned char*)s == (unsigned char)c)
			s++;
		return ((char*)s);
	}
	else
		return (NULL);
}
