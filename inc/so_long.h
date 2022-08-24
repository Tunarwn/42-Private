/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:27:34 by tturna            #+#    #+#             */
/*   Updated: 2022/08/24 16:21:41 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "string.h"
# include "../minilibx/mlx.h"
# include <stdbool.h>
# include "../ft_printf/ft_printf.h"

# define SIZE_X 1000
# define SIZE_Y 800

typedef struct s_game
{
	int		max_y;
	int		max_x;
	void	*window;
	void	*mlx;
	char	**map;
	int		bos;
	int		ps;
	int		coin_count;
	int		p_move;
	int		ply;
	int		plx;

	void	*bg;
	void	*player;
	void	*coin;
	void	*exit;
	void	*wall;
}	t_game;
//Resim dosyalarinin adresleri 39-43
void	ft_exit(char *s);
char	**ft_split(char *s, int i, int i2, int i3);
void	create_map(t_game *tuna, int x, int y);
int		ft_init(t_game *tuna, char **av);
int		ft_strlen(char *s);
int		keys(int key_code, t_game *tuna);
void	put_image(t_game *tuna, void *obj, int x, int y);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_read_map(int fd);
int	check_map(t_game *tuna, int y, int x, char *av);

#endif