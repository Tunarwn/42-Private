/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:37:17 by tturna            #+#    #+#             */
/*   Updated: 2022/08/24 16:29:40 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		s_len--;
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_init(t_game *tuna, char **av)
{
	char	*map;
	int		fd;
	int		i;
	int		len;
	int		result;

	i = -1;
	tuna->max_y = 0;
	fd = open(av[1], O_RDONLY);
	map = ft_read_map(fd);
	len = ft_strlen(map);
	tuna->map = ft_split(map, 0, 0, 0);
	while (tuna->map[++i])
		tuna->max_y++;
	tuna->max_x = ft_strlen(tuna->map[0]);
	check_map(tuna, -1, -1, av[1]);
	close(fd);
	create_map(tuna, -1, -1);
	free(map);
	return (1);
}
