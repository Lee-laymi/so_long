/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:00:37 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/25 23:14:32 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./Libftc/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "math.h"

int		ft_opened(char *path);
int		ft_countpec(char **arr, int mode);
int		ft_checkwallx(char **arr, int i);
int		ft_checkwally(char **arr, int i);
int		ft_checkrec(char **arr, int i);
int		ft_lenx(char *str);
char		**ft_getarr(char **av);
char		ft_checkpath(int ac, char **av);
int		ft_floodfill(char **arr, int x,int y);
void		ft_dupmap(char **arr, int i);
void		ft_check_ac(int ac, char **av);





#endif
