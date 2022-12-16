/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:52:56 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/16 15:25:32 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkwallx(char **arr, int lastrow)
{
	int	k;
	int	lenx;

	k = 0;
	lenx = ft_lenx(arr[0]);
	while (k < lenx)
	{
		if (arr[0][k] != '1')
		{
			write(2, "Map have no wall in x-direction%s\n", 31);
			return (0);
		}
		k++;
	}
	k = 0;
	while (k < lenx)
	{
		if (arr[lastrow - 1][k] != '1')
		{
			write(2, "Map have no wall in x-direction%s\n", 31);
			return (0);
		}
		k++;
	}
	return (1);
}

int	ft_checkwally(char **arr, int lastcolumn)
{
	int		j;
	int		lenx;

	j = 0;
	lenx = ft_lenx(arr[0]);
	while (j < lastcolumn)
	{
		if (arr[j][0] != '1')
		{
			write(2, "Map have no wall in y-direction%s\n", 31);
			return (0);
		}
		j++;
	}
	j = 0;
	while (j < lastcolumn)
	{
		if (arr[j][lenx - 1] != '1')
		{
			write(2, "Map have no wall in y-direction%s\n", 31);
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_checkrec(char **arr, int mapheight)
{
	int		j;
	//int		k;
	int		tmp;
	int		len_rec;

	j = 0;
	//k = 0;
	while (j < mapheight)
	{
		tmp = ft_lenx(arr[0]);
		len_rec = ft_lenx(arr[j]);
		if (tmp != len_rec)
		{
			write(2, "Map is not rectangula%s\n", 22);
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_lenx(char *str)
{
	int		len;

	len = 0;
	while (((str[len]) != '\n') && (str[len] != '\0'))
		len++;
	return (len);
}
