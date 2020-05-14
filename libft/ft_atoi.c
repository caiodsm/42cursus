/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:44:28 by cda-silv          #+#    #+#             */
/*   Updated: 2020/05/10 23:05:28 by cda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_space(int c)
{
	if (c == '\n' || c == ' ' || c == '\v' || c == '\t'
			|| c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

static int			ft_strchar(const char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

static int			ft_strnumber(const char c)
{
	if (ft_strchar(c, "0123456789") == 1)
		return (1);
	return (0);
}

int					ft_atoi(const char *str)
{
	int res;
	int sinal;

	sinal = 1;
	res = 0;
	while (ft_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sinal = (*str == '-') ? -1 : 1;
		str++;
	}
	while (ft_strnumber(*str) == 1)
	{
		res = res * 10 + *str - '0';
		str++;
	}
	res = res * sinal;
	return (res);
}
