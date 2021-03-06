/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:37:18 by wlin              #+#    #+#             */
/*   Updated: 2017/07/14 20:22:26 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	i;
	int len;

	i = 0;
	len = ft_strlen(s1);
	while (*s2 && n--)
		s1[i++ + len] = *s2++;
	s1[i + len] = '\0';
	return (s1);
}
