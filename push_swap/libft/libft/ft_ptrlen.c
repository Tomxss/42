
#include "libft.h"

size_t		ft_ptrlen(char *beg, char *end)
{
	size_t		len;

	if (beg && end)
	{
		len = 0;
		while (beg++ != end)
			len++;
		return (len + 1);
	}
	else
		return (1);
}
