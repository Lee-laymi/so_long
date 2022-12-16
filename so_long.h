/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:00:37 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/16 19:48:13 by ami              ###   ########.fr       */
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
    char    **real_map;
    char    **map;
    
}               t_map;

typedef struct s_dim
{
    int     width;
    int     height;
    int     px;
    int     py;
}               t_dim;

int	    ft_opened(char *av);
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
void    ft_checkmap(char **map_tmp, t_dim dim);
int	    ft_findp(char **map_tmp, t_dim *pos);
int     ft_getposp(char **arr);

#endif