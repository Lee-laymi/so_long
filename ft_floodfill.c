/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:20:35 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/25 23:48:31 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_floodfill(char **arr, int x,int y)
{
	if (arr[x][y] == '0' || arr[x][y] == 'C')
		arr[x][y] = '1';
	else if (arr[x][y] == '1')
		return(0);
	else if (arr[x][y] == 'E')
		return (1);
	ft_floodfill(arr, x, y - 1);
	ft_floodfill(arr, x + 1,y);
	ft_floodfill(arr, x - 1, y);
	ft_floodfill(arr, x, y + 1);
	return (1);
}



