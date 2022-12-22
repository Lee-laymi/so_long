/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:00:21 by ami               #+#    #+#             */
/*   Updated: 2022/12/22 23:01:30 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// void    print_maps(char **map)
// {
//     int i;

//     i = 0;
//     while (map[i])
//     {
//         printf("%s", map[i]);
//         i++;
//     }
// }

int main(int ac, char **av)
{
    int i;
    t_map      map;
    t_dim     dim;

    i = 0;
    ft_check_ac(ac, av);
    ft_initmap(map);
    ft_initdim(dim);
    ft_create_tmpmap(av, &map);
    while (map.tmp_map[i])
    {
        printf(" %s", map.tmp_map[i]);
        i++;
    }
    i = 0;
    ft_create_realmap(av, &map);
    while (map.real_map[i])
    {
        printf(" %s", map.real_map[i]);
        i++;
    }
    //env_map = map_tmp;
    // ft_checkmap(map.tmp_map, dim);
    // ft_floodfillmap(map.tmp_map);

}