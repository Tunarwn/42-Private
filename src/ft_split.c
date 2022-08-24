/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:21:34 by tturna            #+#    #+#             */
/*   Updated: 2022/08/24 14:33:47 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_split(char *s, int i, int i2, int i3)
{
	char	**res;

	res = malloc(1000);
	i2 = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] > 32)
		{
			res[i2] = malloc(1000);
			i3 = 0;
			while (s[i] > 32)
			{
				res[i2][i3] = s[i];
				i++;
				i3++;
			}
			res[i2][i3] = '\0';
			i2++;
		}
		else
			i++;
	}
	res[i2] = 0;
	return (res);
}
