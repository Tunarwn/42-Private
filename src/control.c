/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:39:25 by tturna            #+#    #+#             */
/*   Updated: 2022/08/24 16:50:12 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_read_map(int fd)
{
	char	dizi[2000];
	int		a;
	int		i;
	char	*new;

	i = 0;
	a = read(fd, dizi, 2000);
	dizi[a] = '\0';
	new = ft_strdup(dizi);
	return (new);
}

int	check_map(t_game *tuna, int y, int x, char *av)
{
	while (++y < tuna->max_y)
	{
		x = -1;
		int c;
		
		c = 0;
		if (ft_strlen(tuna->map[y]) != tuna->max_x)
			ft_exit("wrong order !");
		while (++x < tuna->max_x)
		{
			if (tuna->map[y][x] == 'P')
			{
				c++;
				if(c != 1)
				{
					printf("\ntest\n");
					exit(1);
				}
			}
			else if (tuna->map[y][x] != '1' && (y == 0 || y == tuna->max_y - 1))
				ft_exit("wrong wall !");
			else if (tuna->map[y][x] != '1' && (x == 0 || x == tuna->max_x - 1))
				ft_exit("right left check !");
			else if (!ft_strchr("CEP01", tuna->map[y][x]))
				ft_exit("invalid character !");
		}
	}
	return(1);
}

