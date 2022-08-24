/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:36:42 by tturna            #+#    #+#             */
/*   Updated: 2022/08/24 15:38:44 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	maker(t_game *tuna, int x, int y)
{
	if (tuna->map[tuna->ply + y][tuna->plx + x] == 'C')
		tuna->coin_count--;
	if (tuna->map[tuna->ply + y][tuna->plx + x] != '1'
		&&tuna->map[tuna->ply + y][tuna->plx + x] != 'E')
	{
		put_image(tuna, tuna->player, (tuna->plx + x), (tuna->ply + y));
		put_image(tuna, tuna->bg, (tuna->plx), (tuna->ply));
		(tuna)->map[tuna->ply][tuna->plx] = '0';
		(tuna)->map[tuna->ply + y][tuna->plx + x] = 'P';
		tuna->ply += y;
		tuna->plx += x;
		tuna->p_move++;
		ft_printf("                                                  ");
		ft_printf("\033[1;34m\rMoves : %i", tuna->p_move);
	}
	else if (tuna->map[tuna->ply + y][tuna->plx + x] == 'E')
	{
		if (tuna->coin_count == 0)
			exit(0);
		else
			ft_printf("\rDaha toplaman gereken %i tane coin var",
				tuna->coin_count);
	}
}

void	ft_move(t_game *tuna, int dir_x, int dir_y)
{
	int		x;
	int		y;
	bool	breaker;

	breaker = false;
	y = -1;
	while (++y < (tuna)->max_y)
	{
		x = -1;
		while (++x < (tuna)->max_x)
		{
			if ((tuna)->map[y][x] == 'P')
			{
				maker((tuna), dir_x, dir_y);
				breaker = true;
				break ;
			}
			if (breaker)
				break ;
		}
	}
}

int	keys(int key_code, t_game *tuna)
{
	if (key_code == 53)
	{
		exit(0);
	}
	else if (key_code == 13)
		ft_move(tuna, 0, -1);
	else if (key_code == 0)
		ft_move(tuna, -1, 0);
	else if (key_code == 2)
		ft_move((tuna), 1, 0);
	else if (key_code == 1)
		ft_move((tuna), 0, 1);
	return (0);
}
