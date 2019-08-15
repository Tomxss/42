#include "libft.h"

char				*ft_skipspace_end(char *s)
{
	unsigned int	len;

	if (s)
	{
		len = ft_strlen(s);
		if (len == 0)
			return (s);
		s = s + (len - 1);
		while ((*s == ' ' || *s == '\n' || *s == '\t') && len-- > 0)
			s--;
		return (s);
	}
	else
		return (NULL);
}
