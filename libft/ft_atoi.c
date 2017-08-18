/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:38:42 by wlin              #+#    #+#             */
/*   Updated: 2017/08/03 21:18:09 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (!*str || !str)
		return (0);
	while (WS(*str))
		++str;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '+' ? 1 : -1);
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - '0');
	return ((int)num * sign);
}
