/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:52:56 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/25 22:55:26 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		main(int ac, char **av)
{
	char	*check_path;
	int		opened;
	int		i;
	char	**arr;
	int		j;

	ft_checkpath(ac, av);
	ft_getarr(av);
	ft_check_ac(ac, av);

	if (ac < 2 )
		write(2, "agument is not enought %s\n", 21);
	else if (ac > 2)
		write(2,"agument is too much %s\n", 19);
	else
		printf("path = %s\n", av[1]);
	check_path = ft_strnstr(&av[1][ft_strlen(av[1])-4], ".ber", 4);
	printf("file name == %s\n", check_path);
	if (check_path == NULL)
		write(2, "File name is incorrect. Please try again!. %s\n", 42);

	i = ft_opened(av[1]);
	//printf("i = %d\n",i);
	if (i == 0)
		exit (0);
	//printf("Hello \n");
	arr = malloc(sizeof(char *)*(i+1));
	
	arr[i+1] = NULL;
	//printf("Hello2 \n");
	
	opened = open(av[1], O_RDONLY);
	j = 1;
	//printf("opened = %d\n", opened);
	arr[0] = get_next_line(opened);
	while (j <= i)
	{
		arr[j] = get_next_line(opened);
		j++;
	}
	ft_countpec(arr, 1);
	ft_countpec(arr, 2);
	ft_countpec(arr, 3);

	if (ft_checkwallx(arr, i) == 0 )
		write (2, "The wall at x does not complete!\n", 333);
	if (ft_checkwally(arr, i) == 0 )
		write (2, "The wall at y does not complete!\n", 33);
	if (ft_checkrec(arr, i) == 0)
		write (2, "The map is not rectangular!\n", 28);
	ft_dupmap(arr,i);
	return (0);
}

char		**ft_getarr(char **av)
{
	int		opened;
	int		i;
	char	**arr;
	int		j;

	i = ft_opened(av[1]);
	printf("i = %d\n",i);
	if (i == 0)
		exit (0);
	arr = malloc(sizeof(char *)*(i+1));
	arr[i+1] = NULL;
	opened = open(av[1], O_RDONLY);
	j = 1;
	arr[0] = get_next_line(opened);
	while (j <= i)
	{
		arr[j] = get_next_line(opened);
		j++;
	}
	return (arr);
}

char		ft_checkpath(int ac, char **av)
{
	char	*check_path;

	if (ac < 2 )
		write(2, "agument is not enought %s\n", 21);
	else if (ac > 2)
		write(2,"agument is too much %s\n", 19);
	else
		printf("path = %s\n", av[1]);
	check_path = ft_strnstr(&av[1][ft_strlen(av[1])-4], ".ber", 4);
	printf("file name == %s\n", check_path);
	if (check_path == NULL)
		write(2, "File name is incorrect. Please try again!. %s\n", 42);
	return (0);
}

int		ft_countpec(char **arr, int mode)
{
	int		k;
	int		j;
	int		c;

	j = 0;
	c = 0;
	while (arr[j])
	{
		k = 0;
		while (arr[j][k])
		{
			if ((mode == 1) && (arr[j][k] == 'P'))
				c++;
			else if ((mode == 2) && (arr[j][k] == 'E'))
				c++;
			else if ((mode == 3) && (arr[j][k] == 'C'))
					c++;
			k++;
		}
		j++;
	}
	return (c);
}

int		ft_checkwallx(char **arr, int i)
{
		int		k;
		int		lenx;

		k = 0;
		lenx = ft_lenx(arr[0]);
		// printf("len = %d\n",len);
		// printf("arr [0][k0] = %d\n",arr[0][0]);
		// printf("arr [5][k0] = %s\n",arr[4]);
		// printf("i  = %d\n",i);

		while (k < lenx)
		{
			if (arr[0][k] != '1')
			{
				//printf("k = %d\n",k);
				//printf("arr1 = %d\n",arr[0][k]);
				//printf("arr2 = %d\n",arr[i-1][k]);
				return (0);
			}
			k++;
		}
		k = 0;
		while (k < lenx)
		{
			if (arr[i-1][k] != '1')
			{
				//printf("j = %d\n",k);
				return (0);
			}
			k++;
		}
		return (1);
}

int		ft_checkwally(char **arr, int i)
{
		int		j;
		int		lenx;

		j = 0;
		//printf("iy = %d\n", i);
		lenx = ft_lenx(arr[0]);
		//printf("len = %d\n",len);
		//printf("arr [0][k0] = %d\n",arr[0][0]);
		//printf("arr [5][k0] = %s\n",arr[4]);
		//printf("i  = %d\n",i);
		while (j < i)
		{
			if (arr[j][0] != '1') 
			{
				//printf("jy = %d\n",j);
				return (0);
			}
			j++;
		}
		j = 0;
		//printf("jy = %d\n",j);
		//printf("len = %d\n",len);
		while (j < i)
		{
			//printf("arr(y) = %c\n", arr[j][len-1]);
			if (arr[j][lenx-1] != '1')
			{
				//printf("jy = %d\n",j);
				return (0);
			}
			j++;
		}
		return (1);
}
int		ft_checkrec(char **arr, int i)
{
		int		j;
		int		k;
		int		tmp;
		int		len_rec;

		j = 0;
		k = 0;
		//printf("i_rec = %d\n", i);
		while (j < i)
		{
			tmp = ft_lenx(arr[0]);
			len_rec = ft_lenx(arr[j]);
			//printf("len1 = %d\n",tmp);
			//printf("len2 + 1 = %d\n", (len_rec));
			if (tmp != len_rec)
				return (0);
			j++;
		}
		return (1);
}

int		ft_lenx(char *str)
{
	int		len;

	len = 0;
	while (((str[len]) != '\n') && (str[len] != '\0'))
		len++;
	return (len);
}