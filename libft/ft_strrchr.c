/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:49:42 by cda-silv          #+#    #+#             */
/*   Updated: 2020/01/25 17:28:34 by cda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t end;

	end = ft_strlen(s) + 1;
	while (end--)
	{
		if (s[end] == c)
			return ((char*)(s + end));
	}
	return (NULL);
}
