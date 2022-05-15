/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:33:07 by anfreire          #+#    #+#             */
/*   Updated: 2022/05/15 19:20:32 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**map_reciever(int fd)
{
	char	*str;
	char	**matrix;

	if (fd < 0)
	{
		ft_printf("%s\n%s%s", DEFAULT_ERROR, NFOUND, MORE);
		exit (1);
	}
	str = map_checker_v2(map_checker_v1(fd));
	if (str == NULL)
	{
		ft_printf ("%s\n%s%s", DEFAULT_ERROR, MCV2, MORE);
		exit (1);
	}
	matrix = map_checker_v3(str);
	free(str);
	if (matrix == NULL)
	{
		ft_printf ("%s\n%s%s", DEFAULT_ERROR, MCV3, MORE);
		exit (1);
	}
	else
		return (map_reciever_v2(matrix));
}

char	**map_reciever_v2(char **matrix)
{
	matrix = map_checker_v4(matrix);
	if (matrix == NULL)
	{
		ft_printf ("%s\n%s%s", DEFAULT_ERROR, MCV4, MORE);
		exit (1);
	}
	matrix = map_checker_v5(matrix);
	if (matrix == NULL)
	{
		ft_printf ("%s\n%s%s", DEFAULT_ERROR, MCV5, MORE);
		exit (1);
	}
	else
		return (matrix);
}
