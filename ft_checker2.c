/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:52:56 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/14 19:25:20 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkwallx(char **arr, int i)
{
	int	k;
	int	lenx;

		k = 0;
		lenx = ft_lenx(arr[0]);
	while (k < lenx)
	{
		if (arr[0][k] != '1')
		{
			return (0);
		}
		k++;
	}
	k = 0;
	while (k < lenx)
	{
		if (arr[i - 1][k] != '1')
		{
			return (0);
		}
		k++;
	}
	return (1);
}

int	ft_checkwally(char **arr, int i)
{
	int		j;
	int		lenx;

	j = 0;
	lenx = ft_lenx(arr[0]);
	while (j < i)
	{
		if (arr[j][0] != '1')
		{
			return (0);
		}
		j++;
	}
	j = 0;
	while (j < i)
	{
		if (arr[j][lenx - 1] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_checkrec(char **arr, int i)
{
	int		j;
	//int		k;
	int		tmp;
	int		len_rec;

	j = 0;
	//k = 0;
	while (j < i)
	{
		tmp = ft_lenx(arr[0]);
		len_rec = ft_lenx(arr[j]);
		if (tmp != len_rec)
			return (0);
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
