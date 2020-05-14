/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:36:04 by cda-silv          #+#    #+#             */
/*   Updated: 2020/05/09 04:17:57 by cda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size;
	char		*new;
	const char	*front_limit;
	const char	*back_limit;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	front_limit = s1;
	back_limit = s1 + size - 1;
	while (ft_strchr(set, *front_limit) && front_limit < back_limit)
		front_limit++;
	while (ft_strchr(set, *back_limit) && back_limit > front_limit)
		back_limit--;
	size = (back_limit == front_limit) ? 0 : back_limit - front_limit + 1;
	new = (char *)malloc(sizeof(char) * size + 1);
	if (new == 0)
		return (NULL);
	ft_memcpy(new, front_limit, size);
	new[size] = '\0';
	return (new);
}
