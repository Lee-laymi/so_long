/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:00:21 by ami               #+#    #+#             */
/*   Updated: 2022/12/16 20:54:06 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void    print_maps(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        printf("%s", map[i]);
        i++;
    }
}

int main(int    ac, char   **av)
{
    int i;
    char    **map_tmp;
    t_map      env_map;
    t_dim     dim;

    ft_check_ac(ac, av);
   
    map_tmp = ft_createmap(av, &env_map);
    //ft_checkmap(map_tmp, dim);
    // if (ft_floodfill(map_tmp, dim->width, dim->height) != 1)
    //     {
    //         write(2, "Map is incorrect. Please try again!. %s\n", 38);
    //         ft_freemap(map_tmp);
	// 		exit (0);
    //     }
    // env_map->real_map = ft_createmap(av, &env_map->real_map);
    ft_getposp(map_tmp);
	


}