/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:00:37 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/22 17:39:46 by ami              ###   ########.fr       */
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
    char    **tmp_map;
    
}               t_map;

typedef struct s_dim
{
    int     width;
    int     height;
    int     px;
    int     py;
}               t_dim;

// typedef struct s_program
// {
//     t_dim   dime;
//     t_map   map;
// }

int	    ft_opened(char *av);
int		ft_countpec(t_map *map, int mode);
int		ft_checkwallx(t_map *map, int lastrow);
int		ft_checkwally(t_map *map, int lastcolumn);
int		ft_checkrec(t_map *map, int i);
int		ft_lenx(char *str);
char	**ft_create_tmpmap(char **av, t_map *map);
int	    ft_floodfill(t_map *map, int x, int y);
void	ft_check_ac(int ac, char **av);
void	ft_freemap(char **tmp_map);
int	    ft_checkpec(char **tmp_map);
void    ft_checkmap(char **tmp_map, t_dim dim);
int	    ft_findp(char **tmp_map, t_dim *pos);
int     ft_floodfillmap(t_map *map);
char	**ft_create_realmap(char **av, t_map *map);
void	ft_initmap(t_map map);
void	ft_initdim(t_dim dim);

#endif