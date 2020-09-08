/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xubuntu <xubuntu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:51:17 by cda-silv          #+#    #+#             */
/*   Updated: 2020/09/05 16:30:35 by cda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	ft_free_null(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}

static	int		ft_concatena(char **line, char **buff)
{
	int		i;
	int		j;
	char	tmp[ARG_MAX];

	i = 0;
	j = 0;
	while (line[0][i] != '\0')
	{
		tmp[i] = line[0][i];
		i++;
	}
	ft_free_null(&*line);
	while (buff[0][j] != '\0' && buff[0][j] != '\n')
		tmp[i++] = buff[0][j++];
	tmp[i] = '\0';
	*line = ft_strdup(tmp);
	return (j);
}

int				ft_bufftoline(char **buff, char **line)
{
	long long	i;
	long long	j;
	char		*tmp[ARG_MAX];

	i = ft_concatena(*&line, *&buff);
	if (buff[0][i] == '\n')
	{
		if (buff[0][i + 1] == '\0')
			ft_free_null(&*buff);
		else
		{
			j = ft_strlen(buff[0]);
			tmp[0] = ft_substr(buff[0], i + 1, j);
			ft_free_null(&*buff);
			buff[0] = tmp[0];
		}
		return (1);
	}
	ft_free_null(&*buff);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			tmp[ARG_MAX];
	int				r[2];
	static char		*buff[OPEN_MAX];

	if (fd >= 0 && line && BUFFER_SIZE > 0 && (*line = ft_strdup("")))
	{
		r[0] = SEM_BARRA_N;
		while (r[0] == SEM_BARRA_N)
		{
			if (buff[fd] == NULL && (r[1] = read(fd, tmp, BUFFER_SIZE)) >= 0
				&& (tmp[r[1]] = '\0') == 0)
				buff[fd] = ft_strdup(tmp);
			if (buff[fd] != NULL)
				r[1] = ft_strlen(buff[fd]);
			if (r[1] < 0)
				break ;
			r[0] = ft_bufftoline(&buff[fd], *&line);
			if (r[1] == 0)
				return (END);
		}
		if (r[0] == COM_BARRA_N)
			return (COM_BARRA_N);
	}
	ft_free_null(&*line);
	return (-1);
}
