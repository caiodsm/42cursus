/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:38:18 by cda-silv          #+#    #+#             */
/*   Updated: 2020/01/25 17:12:23 by cda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int len_find;

	len_find = ft_strlen(to_find);
	if (len_find == 0)
		return ((char*)str);
	while (*str && len >= len_find)
	{
		if (!ft_strncmp(str, to_find, len_find))
			return ((char*)str);
		str++;
		len--;
	}
	return (NULL);
}
