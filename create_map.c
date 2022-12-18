/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:08:58 by ami               #+#    #+#             */
/*   Updated: 2022/12/18 17:30:06 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"



char	**ft_create_tmpmap(char **av, t_map *map)
{
	int		opened;
	t_dim	dim;
	//int		i;
	int		j;

	dim.height = ft_opened(av[1]);
	//printf("i = %d\n", i);
    if (dim.height == 0)
	{
		write(2, "Map Error\n", 10);
		exit (0);
	}
	map->tmp_map = malloc(sizeof(char *) * (dim.height + 1));
	opened = open(av[1], O_RDONLY);
	j = 0;
	map->tmp_map[j] = get_next_line(opened);
	while (map->tmp_map[j])
	{
		j++;
		map->tmp_map[j] = get_next_line(opened);
	}
	map->tmp_map[j] = NULL;
	return (map->tmp_map);
}

char	**ft_create_realmap(char **av, t_map *map)
{
	int		opened;
	t_dim	dim;
	//int		i;
	int		j;

	dim.height = ft_opened(av[1]);
	//printf("i = %d\n", i);
    if (dim.height == 0)
	{
		write(2, "Map Error\n", 10);
		exit (0);
	}
	map->real_map = malloc(sizeof(char *) * (dim.height + 1));
	opened = open(av[1], O_RDONLY);
	j = 0;
	map->real_map[j] = get_next_line(opened);
	while (map->real_map[j])
	{
		j++;
		map->real_map[j] = get_next_line(opened);
	}
	map->real_map[j] = NULL;
	return (map->real_map);
}

void	ft_freemap(char **tmp_map)
{
        int i;

	while (tmp_map[i])
	{
		free(tmp_map[i]);
        i++;
	}
    free(tmp_map);
    exit(0);
}

void    ft_checkmap(char **tmp_map, t_dim dim)
{
	if (ft_checkpec(tmp_map) != 1)
		{
			ft_freemap(tmp_map);
			exit (0);
		}
	else if (ft_checkwallx(tmp_map, dim.height) != 1)
		{
			ft_freemap(tmp_map);
			exit (0);
		}
	else if (ft_checkwally(tmp_map, dim.width) != 1)
		{
			ft_freemap(tmp_map);
			exit (0);
		}
	else if (ft_checkrec(tmp_map, dim.height) != 1)
		{
			ft_freemap(tmp_map);
			exit (0);
		}
}