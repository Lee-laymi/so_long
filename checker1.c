/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:11:28 by ami               #+#    #+#             */
/*   Updated: 2022/12/18 15:44:35 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_check_ac(int ac, char **av)
{
	char	*check_path;
	int		i;

	if (ac < 2)
	{
		write(2, "agument is not enought %s\n", 21);
		exit (0);
	}
	else if (ac > 2)
	{
		write(2, "agument is too much %s\n", 19);
		exit (0);
	}
	check_path = ft_strnstr(&av[1][ft_strlen(av[1]) - 4], ".ber", 4);
	if (check_path == NULL)
	{
		write(2, "File name is incorrect. Please try again!. %s\n", 42);
		exit (0);
	}
}

// char	ft_checkpath(int ac, char **av)
// {
// 	char	*check_path;

// 	if (ac < 2)
// 		write(2, "agument is not enought %s\n", 21);
// 	else if (ac > 2)
// 		write(2, "agument is too much %s\n", 19);
// 	else
// 		printf("path = %s\n", av[1]);
// 	check_path = ft_strnstr(&av[1][ft_strlen(av[1]) - 4], ".ber", 4);
// 	printf("file name == %s\n", check_path);
// 	if (check_path == NULL)
// 		write(2, "File name is incorrect. Please try again!. %s\n", 42);
// 	return (0);
// }

int	ft_countpec(char **arr, int mode)
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

int	ft_checkpec(char **tmp_map)
{
    if (ft_countpec(tmp_map, 1) != 1 )
	{
		write(2, "Map have no P%s\n", 13);
        ft_freemap(tmp_map);
	}
	if (ft_countpec(tmp_map, 2) != 1 )
	{
		write(2, "Map have no E%s\n", 13);
        ft_freemap(tmp_map);
	}
	if (ft_countpec(tmp_map, 3) < 1 )
    {
		write(2, "Map have no C%s\n", 13);
        ft_freemap(tmp_map);
	}
    else
        return (1);
}
