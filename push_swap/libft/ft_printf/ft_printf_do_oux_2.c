/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_oux_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:45:26 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/31 14:45:29 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_do_oux_j(uintmax_t o, t_com **com, int base)
{
	(*com)->scroll = ft_itoa_base_uintmax(o, (uintmax_t)base);
}

void	ft_do_oux_z(size_t o, t_com **com, int base)
{
	(*com)->scroll = ft_itoa_base_uintmax(o, (uintmax_t)base);
}

void	ft_do_oo(long int d, t_com **com)
{
	ft_do_oux_l((unsigned long int)d, *&com, 8);
	(*com)->len = ft_strlen((*com)->scroll);
}

void	ft_do_uu(long int u, t_com **com)
{
	ft_do_oux_l((unsigned long)u, *&com, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}
