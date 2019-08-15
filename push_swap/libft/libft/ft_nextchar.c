#include "libft.h"

char	ft_nextchar(char c)
{
	if (c > 122 || c < 65)
		return (48);
	if (c >= 65 && c < 122)
		return (c + 1);
	if (c == 122)
		return (65);
	return (48);
}
