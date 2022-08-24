/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:04:23 by tturna            #+#    #+#             */
/*   Updated: 2022/08/24 14:33:14 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	*tuna;
	int		i;

	tuna = malloc(sizeof(t_game));
	tuna->coin_count = 0;
	tuna->p_move = 0;
	if (!tuna)
		return (0);
	i = 0;
	if (ac == 2)
	{
		tuna->ps = 50;
		if (!ft_init(tuna, av))
			ft_exit("error");
	}
	else
		ft_exit("argument error");
	mlx_hook(tuna->window, 2, 1L << 0, keys, tuna);
	mlx_loop(tuna->mlx);
}
