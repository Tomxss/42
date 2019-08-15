#include "libft.h"

char	*ft_strchrto_end(char *s, char c)
{
	char	*copy;
	char	*temp;

	if (*s)
	{
		copy = (char*)malloc(sizeof(char) * ((ft_strlen(s) + 2)));
		ft_strcpy(copy, s);
		temp = copy;
		while (*temp)
			temp++;
		*temp = c;
		temp = temp + 1;
		*temp = '\0';
		return (copy);
	}
	else
		return (NULL);
}
