
#include "libftprintf.h"

void	ft_do_d_j(intmax_t d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}

void	ft_do_d_z(size_t d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}

void	ft_do_dd(long int d, t_com **com)
{
	ft_do_d_l(d, *&com);
	(*com)->len = ft_strlen((*com)->scroll);
}

void	ft_do_i(int i, t_com **com)
{
	(*com)->scroll = ft_itoa_base(i, 10);
}
