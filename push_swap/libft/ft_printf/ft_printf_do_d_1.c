/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_d_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:44:58 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:45:02 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_do_d(int d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}

void	ft_do_d_h(short d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}

void	ft_do_d_hh(signed char d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}

void	ft_do_d_l(long d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}

void	ft_do_d_ll(long long d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}
