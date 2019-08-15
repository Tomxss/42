/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 07:24:30 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/08/12 07:24:34 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXTRA_H
# define FT_EXTRA_H

# include "../libft/libft.h"

void			*ft_memnncpy(void *dst, const void *src, size_t beg, size_t n);
char			*ft_itoa_base_uintmax(uintmax_t value, uintmax_t base);
char			*ft_itoa_base(intmax_t value, intmax_t base);
char			*ft_strdel_begn(char *str, size_t n);
char			*ft_strdupn(const char *str, size_t n);
size_t			ft_wcharlen(wchar_t wchar);

#endif
