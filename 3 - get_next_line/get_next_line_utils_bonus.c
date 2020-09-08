/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xubuntu <xubuntu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:54:55 by cda-silv          #+#    #+#             */
/*   Updated: 2020/09/06 03:03:37 by cda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(sub = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while ((i < len) && (start + i) < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = -1;
	if (!(dup = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
