/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:52:56 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/22 17:24:18 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkwallx(t_map *map, int lastrow)
{
	int	k;
	int	lenx;

	k = 0;
	lenx = ft_lenx(map->tmp_map[0]);
	while (k < lenx)
	{
		if (map->tmp_map[0][k] != '1')
		{
			write(2, "Map have no wall in x-direction%s\n", 31);
			return (0);
		}
		k++;
	}
	k = 0;
	while (k < lenx)
	{
		if (map->tmp_map[lastrow - 1][k] != '1')
		{
			write(2, "Map have no wall in x-direction%s\n", 31);
			return (0);
		}
		k++;
	}
	return (1);
}

int	ft_checkwally(t_map *map, int lastcolumn)
{
	int		j;
	int		lenx;

	j = 0;
	lenx = ft_lenx(map->tmp_map[0]);
	while (j < lastcolumn)
	{
		if (map->tmp_map[j][0] != '1')
		{
			write(2, "Map have no wall in y-direction%s\n", 31);
			return (0);
		}
		j++;
	}
	j = 0;
	while (j < lastcolumn)
	{
		if (map->tmp_map[j][lenx - 1] != '1')
		{
			write(2, "Map have no wall in y-direction%s\n", 31);
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_checkrec(t_map *map, int mapheight)
{
	int		j;
	//int		k;
	int		tmp;
	int		len_rec;

	j = 0;
	//k = 0;
	while (j < mapheight)
	{
		tmp = ft_lenx(map->tmp_map);
		len_rec = ft_lenx(map->tmp_map[j]);
		if (tmp != len_rec)
		{
			write(2, "Map is not rectangula%s\n", 22);
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_lenx(char *str)
{
	int		len;

	len = 0;
	while (((str[len]) != '\n') && (str[len] != '\0'))
		len++;
	return (len);
}
