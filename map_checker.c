/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:42:30 by anfreire          #+#    #+#             */
/*   Updated: 2022/05/14 13:30:10 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*map_checker_v1(int fd)
{
	char	*buff;
	char	*tmp;
	char	*dst;

	tmp = NULL;
	buff = get_next_line(fd);
	while (buff != 0)
	{
		if (!tmp)
			tmp = ft_strdup("");
		dst = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = ft_strdup(dst);
		free(dst);
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	tmp = ft_strtrim(tmp, "\n");
	buff = tmp;
	free(tmp);
	return (buff);
}

char	*map_checker_v2(char *str)
{
	size_t	i;
	int		cmpnts[3];

	cmpnts[2] = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == 10 || str[i] == 48 || str[i] == 49
			|| str[i] == 67 || str[i] == 69 || str[i] == 80)
		{
			if (str[i] == 69)
				cmpnts[0] = 1;
			if (str[i] == 67)
				cmpnts[1] = 1;
			if (str[i] == 80)
				cmpnts[2] = 1;
			i++;
		}
		else
			return (NULL);
	}
	if (cmpnts[0] != 1 || cmpnts[1] != 1 || cmpnts[2] != 1)
		return (NULL);
	return (only_one_player(str));
}

char	**map_checker_v3(char *str)
{
	char	**dest;
	char	*ptr;
	int		spc;

	dest = ft_split(str, 10);
	while (*str)
	{
		ptr = ft_strchr(str, 10);
		if (ptr)
		{
			spc = (ptr - str);
			if (spc == 0)
				return (NULL);
			str += spc + 1;
		}
		else
			break ;
	}
	return (dest);
}

char	**map_checker_v4(char **matrix)
{
	size_t	array_len;
	int		matrix_len;
	int		i;

	i = 0;
	matrix_len = -1;
	array_len = ft_strlen(matrix[i]);
	matrix_len = matrix_heigh(matrix);
	while (i < matrix_len)
	{
		if (ft_strlen(matrix[i]) != array_len)
			return (NULL);
		i++;
	}
	return (matrix);
}

char	**map_checker_v5(char **matrix)
{
	size_t	array_len;
	int		matrix_len;
	int		i;

	i = 0;
	matrix_len = -1;
	array_len = ft_strlen(matrix[i]);
	matrix_len = matrix_heigh(matrix);
	while (i < matrix_len)
	{
		if (matrix[i][0] != 49)
			return (NULL);
		if (matrix[i][array_len - 1] != 49)
			return (NULL);
		i++;
	}
	i = -1;
	while (++i < (int)array_len)
	{
		if (matrix[0][i] != 49)
			return (NULL);
		if (matrix[matrix_len - 1][i] != 49)
			return (NULL);
	}
	return (matrix);
}
