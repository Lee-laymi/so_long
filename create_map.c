/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:08:58 by ami               #+#    #+#             */
/*   Updated: 2022/12/14 22:05:58 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

char	**ft_createmap(char **av, t_map *map)
{
	int		opened;
	//int		i;
	int		j;

	map->height = ft_opened(av[1]);
	//printf("i = %d\n", i);
	if (map->height == 0)
		exit (0);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	opened = open(av[1], O_RDONLY);
	j = 1;
	map->map[0] = get_next_line(opened);
	while (j <= map->height)
	{
		map->map[j] = get_next_line(opened);
		j++;
	}
	return (map->map);
}

void	ft_freemap(char **map)
{
        int i;

	while (map[i])
	{
		free(map[i]);
        i++;
	}
    free(map);
    exit(0);
}

void    ft_checkmap(t_map map_tmp)
{
    ft_checkpec(map_tmp.map);
    ft_checkwallx(map_tmp.map, map_tmp.height);
}