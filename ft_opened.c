/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opened.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:51:01 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/14 22:10:58 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_opened(char *av)
{
	int		opened;
	char	*str;
	int		i;

	opened = open(av, O_RDONLY);
	//printf("opened = %d\n", opened);
	if (opened < 0)
	{
		write(2, "File not found", 14);
		return (0);
	}
	str = get_next_line(opened);
	//printf("str = %s\n", str);
	i = 0;
	while (str)
	{
		free(str);
		str = get_next_line(opened);
		// printf("str = %s\n", str);
		i++;
	}
	free (str);
	close (opened);
	return (i);
}