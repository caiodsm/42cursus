/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:41:34 by cda-silv          #+#    #+#             */
/*   Updated: 2020/05/09 04:32:04 by cda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	d;
	size_t	i;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (dstsize == 0)
		return (s);
	i = 0;
	if (dstsize > d)
		while (src[i] && i < dstsize - d - 1)
		{
			dst[d + i] = src[i];
			i++;
		}
	if (d + i <= dstsize)
		dst[d + i] = '\0';
	return (dstsize < d) ? (s + dstsize) : (s + d);
}
