/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_old1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:52:56 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/14 17:22:48 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*check_path;
	int		i;
	char	**arr;
	char	**arr_tmp;

	ft_checkpath(ac, av);
	ft_check_ac(ac, av);
	arr = ft_getarr(av);
	ft_check_ac(ac, av);
	if (ac < 2)
		write(2, "agument is not enought %s\n", 21);
	else if (ac > 2)
		write(2, "agument is too much %s\n", 19);
	else
		printf("path = %s\n", av[1]);
	check_path = ft_strnstr(&av[1][ft_strlen(av[1]) - 4], ".ber", 4);
	printf("file name == %s\n", check_path);
	if (check_path == NULL)
		write(2, "File name is incorrect. Please try again!. %s\n", 42);
	i = ft_opened(av[1]);
	ft_countpec(arr, 1);
	ft_countpec(arr, 2);
	ft_countpec(arr, 3);
	if (ft_checkwallx(arr, i) == 0)
		write (2, "The wall at x does not complete!\n", 33);
	if (ft_checkwally(arr, i) == 0)
		write (2, "The wall at y does not complete!\n", 33);
	if (ft_checkrec(arr, i) == 0)
		write (2, "The map is not rectangular!\n", 28);
	arr_tmp = ft_getarr(av);
	//y = 0;
	// while (arr_tmp[y])
	// {
	// 	printf("arr_dupmap = %s\n", arr[y]);
	// 	y++;
	// }
	// printf("hello\n");
	// ft_dupmap(arr_tmp, i);
	//ทำ function หาตำแหน่ง P ก่อนส่งเข้า floodfill
	//ft_floodfill(arr_tmp, x, y);
	return (0);
}
