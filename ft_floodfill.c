/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:20:35 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/18 17:33:13 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_floodfill(t_map *map, int x, int y)
{
	t_dim	dim;
	
	dim.height = ft_opened(av[1]);
	dim.width = ft_opened(av[1]);
	if ((x < 0 || y < 0) || (x >= dim.width || y >= dim.height))
	if (map->tmp_map[x][y] == '0' || map->tmp_map[x][y] == 'C' || map->tmp_map[x][y] == 'W')
		map->tmp_map[x][y] = 'W';
	else if (map->tmp_map[x][y] == '1')
		return (0);
	else if (map->tmp_map[x][y] == 'E')
		return (1);
	ft_floodfill(map->tmp_map, x, y - 1);
	ft_floodfill(map->tmp_map, x + 1, y);
	ft_floodfill(map->tmp_map, x - 1, y);
	ft_floodfill(map->tmp_map, x, y + 1);
	return (1);
}

int	ft_findp(t_map *map, t_dim *pos)
{
	pos->px = 0;
	while (map->tmp_map[pos->px])
	{
		pos->py = 0;
		while (map->tmp_map[pos->px][pos->py])
		{
			if (map->tmp_map[pos->px][pos->py] == 'P')
				return (0);
			pos->py++;
		}
		pos->px++;
	}
	return (0);
}

int ft_floodfillmap(t_map *map)
{
	t_dim	pos;
	
	pos.px = 0;
	pos.py = 0;
	ft_findp(map->tmp_map, &pos);
	printf("pos.px = %d\n", pos.px);
	printf("pos.py = %d\n", pos.py);
	 if (ft_floodfill(map->tmp_map, pos.px, pos.py) != 1)
        {
            write(2, "Map is incorrect. Please try again!. %s\n", 38);
            ft_freemap(map->tmp_map);
			exit (0);
        } 
}