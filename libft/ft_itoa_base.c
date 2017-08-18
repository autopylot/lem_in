/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:25:29 by wlin              #+#    #+#             */
/*   Updated: 2017/08/03 21:35:11 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_base(int nbr, int base)
{
	char	*str;
	long	temp;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	if (nbr == 0)
		return (strdup("0"));
	temp = (nbr < 0 ? -(long)value : (long)value);
	len = (value < 0 ? 2 : 1);
	while (nbr /= base)
		++len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	(value < 0) ? s[0] = '-' : 0;
	n = (value < 0) ? -(long)value : value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (s);
}
