/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:00:37 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/23 23:35:31 by skrairab         ###   ########.fr       */
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
# include "./ftc_getnextline/get_next_line.h"
# include "math.h"

int		ft_opened(char *path);
int		ft_countpec(char **arr, int i, int mode);
int		ft_checkwallx(char **arr, int i);
int		ft_checkwally(char **arr, int i);
int		ft_checkrec(char **arr, int i);
int		ft_lenx(char *str);



#endif
