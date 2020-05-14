/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:09:46 by cda-silv          #+#    #+#             */
/*   Updated: 2020/02/29 18:38:49 by cda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_free2(char **str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

static int		ft_ls(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

static	int		ft_ts(char const *str, char c)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		l;

	i = -1;
	j = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_ts(s, c) + 1))))
		return (NULL);
	while (ft_ts(s, c) > ++i)
	{
		l = 0;
		if (!(tab[i] = (char*)malloc(sizeof(char) * ((ft_ls(&s[j], c) + 1)))))
		{
			ft_free2(tab, j);
			return (0);
		}
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			tab[i][l++] = s[j++];
		tab[i][l] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
