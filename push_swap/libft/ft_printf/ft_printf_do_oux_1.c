#include "libftprintf.h"

void	ft_do_oux(unsigned int o, t_com **com, int base)
{
	(*com)->scroll = ft_itoa_base(o, base);
}

void	ft_do_oux_hh(unsigned char o, t_com **com, int base)
{
	(*com)->scroll = ft_itoa_base(o, base);
}

void	ft_do_oux_h(unsigned short o, t_com **com, int base)
{
	(*com)->scroll = ft_itoa_base(o, base);
}

void	ft_do_oux_ll(unsigned long long o, t_com **com, int base)
{
	(*com)->scroll = ft_itoa_base_uintmax(o, (uintmax_t)base);
}

void	ft_do_oux_l(unsigned long o, t_com **com, int base)
{
	(*com)->scroll = ft_itoa_base_uintmax(o, (uintmax_t)base);
}
