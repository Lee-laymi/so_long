/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:08:58 by ami               #+#    #+#             */
/*   Updated: 2022/12/16 20:51:13 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

char	**ft_createmap(char **av, t_map *map)
{
	int		opened;
	t_dim	dim;
	//int		i;
	int		j;

	dim.height = ft_opened(av[1]);
	//printf("i = %d\n", i);
    if (dim.height == 0)
		exit (0);
	map->map = malloc(sizeof(char *) * (dim.height + 1));
	opened = open(av[1], O_RDONLY);
	if (opened < 0)
	{
		//error
		exit(0);
	}
	j = 0;
	map->map[j] = get_next_line(opened);
	while (map->map[j])
	{
		j++;
		map->map[j] = get_next_line(opened);
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

void    ft_checkmap(char **map_tmp, t_dim dim)
{
	if (ft_checkpec(map_tmp) != 1)
		{
			ft_freemap(map_tmp);
			exit (0);
		}
	else if (ft_checkwallx(map_tmp, dim.height) != 1)
		{
			ft_freemap(map_tmp);
			exit (0);
		}
	else if (ft_checkwally(map_tmp, dim.width) != 1)
		{
			ft_freemap(map_tmp);
			exit (0);
		}
	else if (ft_checkrec(map_tmp, dim.height) != 1)
		{
			ft_freemap(map_tmp);
			exit (0);
		}
}