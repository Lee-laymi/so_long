/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:20:35 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/16 19:40:18 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_floodfill(char **arr, int x, int y)
{
	t_dim	*dim;
	
	if ((x < 0 || y < 0) || (x >= dim->width || y >= dim->height))
	if (arr[x][y] == '0' || arr[x][y] == 'C' || arr[x][y] == 'W')
		arr[x][y] = 'W';
	else if (arr[x][y] == '1')
		return (0);
	else if (arr[x][y] == 'E')
		return (1);
	ft_floodfill(arr, x, y - 1);
	ft_floodfill(arr, x + 1, y);
	ft_floodfill(arr, x - 1, y);
	ft_floodfill(arr, x, y + 1);
	return (1);
}

int	ft_findp(char **map_tmp, t_dim *pos)
{
	pos->px = 0;
	while (map_tmp[pos->px])
	{
		pos->py = 0;
		while (map_tmp[pos->px][pos->py])
		{
			if (map_tmp[pos->px][pos->py] == 'P')
				return (0);
			pos->py++;
		}
		pos->px++;
	}
	return (0);
}

int ft_getposp(char **arr)
{
	t_dim	pos;
	
	pos.px = 0;
	pos.py = 0;
	ft_findp(arr, &pos);
	printf("pos.px = %d\n", pos.px);
	printf("pos.py = %d\n", pos.py);
}