/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opened.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:51:01 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/25 23:51:19 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_opened(char *path)
{
	int		opened;
	char	*str;
	int		i;

	opened = open(path, O_RDONLY);
	//printf("opened = %d\n", opened);
	if (opened < 0)
	{
		write(2, "File not found", 14);
		return (0);
	}
	str = get_next_line(opened);
	printf("str = %s\n", str);
	i = 0;
	while (str)
	{
		free(str);
		str = get_next_line(opened);
		printf("str = %s\n", str);
		i++;
	}
	free (str);
	close (opened);
	return (i);
}

void		ft_dupmap(char **arr, int i)
{
	char	**arr_tmp;
	int		lenx;
	int		y;

	y = 0;
	arr_tmp = ft_getarr(arr);
	lenx = ft_lenx(arr[0]);
	while (arr[y])
	{
		printf("arr_dupmap = %s\n", arr[y]);
		y++;
	}
}


void		ft_check_ac(int ac, char **av)
{
	char	*check_path;
	int		i;

	if (ac < 2 )
	{
		write(2, "agument is not enought %s\n", 21);
		exit (0);
	}
	else if (ac > 2)
	{
		write(2,"agument is too much %s\n", 19);
		exit (0);
	}
	else
		printf("path = %s\n", av[1]);
	check_path = ft_strnstr(&av[1][ft_strlen(av[1])-4], ".ber", 4);
	printf("file name == %s\n", check_path);
	if (check_path == NULL)
	{
		write(2, "File name is incorrect. Please try again!. %s\n", 42);
		exit (0);
	}
	i = ft_opened(av[1]);
	//printf("i = %d\n",i);
	if (i == 0)
		exit (0);
}

