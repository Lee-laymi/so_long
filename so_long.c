/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:00:21 by ami               #+#    #+#             */
/*   Updated: 2022/12/14 22:16:06 by ami              ###   ########.fr       */
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
    t_map   real_map;

    ft_check_ac(ac, av);
    map_tmp = ft_createmap(av, &real_map);
    print_maps(map_tmp);
    // real_map.map = ft_createmap(av[1]);
	
    
    



}