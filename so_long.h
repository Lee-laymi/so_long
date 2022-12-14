/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:00:37 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/14 22:14:25 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./Libfts/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "math.h"
# include "./ft_getnextline/get_next_line.h"

typedef struct s_map
{
    char    *path;
    char    **map;
    int     width;
    int     height;
}               t_map;

int		ft_opened(char *path);
int		ft_countpec(char **arr, int mode);
int		ft_checkwallx(char **arr, int i);
int		ft_checkwally(char **arr, int i);
int		ft_checkrec(char **arr, int i);
int		ft_lenx(char *str);
char	**ft_createmap(char **av, t_map *map);
int		ft_floodfill(char **arr, int x, int y);
void	ft_check_ac(int ac, char **av);
void	ft_freemap(char **map);
int	    ft_checkpec(char **map_tmp);

#endif