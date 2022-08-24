/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:15:20 by tturna            #+#    #+#             */
/*   Updated: 2022/08/24 15:27:45 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *tuna, void *obj, int x, int y)
{
	mlx_put_image_to_window(tuna->mlx, tuna->window, obj, x * tuna->ps,
		y * tuna->ps);
}

void	obj(t_game *tuna, int x, int y)
{
	while (++y < tuna->max_y)
	{
		x = -1;
		while (++x < tuna->max_x)
		{
			
			if (tuna->map[y][x] == '1')
				put_image(tuna, tuna->wall, x, y);
			else if (tuna->map[y][x] == '0')
				put_image(tuna, tuna->bg, x, y);
			else if (tuna->map[y][x] == 'E')
				put_image(tuna, tuna->exit, x, y);
			else if (tuna->map[y][x] == 'C')
			{
				put_image(tuna, tuna->coin, x, y);
				tuna->coin_count++;
			}
			else if (tuna->map[y][x] == 'P')
			{
				put_image(tuna, tuna->player, x, y);
				tuna->plx = x;
				tuna->ply = y;
			}
		}
	}
}

void	mlx_convertxpms(t_game *tuna)
{
	tuna->bg = mlx_xpm_file_to_image(tuna->mlx,
			"./sprites/ways.xpm", &tuna->bos, &tuna->bos);
	tuna->wall = mlx_xpm_file_to_image(tuna->mlx,
			"./sprites/wall.xpm", &tuna->bos, &tuna->bos);
	tuna->exit = mlx_xpm_file_to_image(tuna->mlx,
			"./sprites/exitnew.xpm", &tuna->bos, &tuna->bos);
	tuna->coin = mlx_xpm_file_to_image(tuna->mlx,
			"./sprites/coin2.xpm", &tuna->bos, &tuna->bos);
	tuna->player = mlx_xpm_file_to_image(tuna->mlx,
			"./sprites/car.xpm", &tuna->bos, &tuna->bos);
}

void	create_map(t_game *tuna, int x, int y)
{
	tuna->mlx = mlx_init();
	tuna->window = mlx_new_window
		(tuna->mlx, tuna->max_x * 50, tuna->max_y * 50, "so_long");
	mlx_convertxpms(tuna);
	obj(tuna, -1, -1);
}
