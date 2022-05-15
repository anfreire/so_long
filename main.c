/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:43:30 by anfreire          #+#    #+#             */
/*   Updated: 2022/05/15 19:17:57 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_win(t_param *param)
{
	int	i;

	i = 0;
	mlx_destroy_window(param->mlx.mlx, param->mlx.win);
	free_images(param);
	while (i < matrix_heigh(param->matrix))
	{
		free(param->matrix[i]);
		i++;
	}
	free(param->matrix);
	system("leaks -- so_long");
	exit (0);
	return (0);
}

int	exit_true(t_param	*param)
{
	int	i;
	int	j;
	int	b00l;

	b00l = 0;
	i = 0;
	while (param->matrix[i])
	{
		j = 0;
		while (param->matrix[i][j])
		{
			if (param->matrix[i][j] == 'E')
				b00l++;
			j++;
		}
		i++;
	}
	return (b00l);
}

int	main(int ac, char *av[])
{
	int			fd;
	t_param		param;
	int			len;
	const char	*ber;
	const char	ber_orig[5] = ".ber";

	if (ac != 2)
	{
		ft_printf("%s\nYou didn't enter any map!", DEFAULT_ERROR);
		return (0);
	}
	len = (int)ft_strlen(av[1]);
	ber = &(av[1])[len - 4];
	if (ft_strncmp(ber, ber_orig, 5))
	{
		ft_printf("%s\nMap file extension not supported!", DEFAULT_ERROR);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	param.matrix = heigh_calc(fd, &param);
	start_mlx_process(&param);
	return (0);
}

char	*only_one_player(char	*str)
{
	size_t	i;
	int		p;

	p = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == 10 || str[i] == 48 || str[i] == 49
			|| str[i] == 67 || str[i] == 69 || str[i] == 80)
		{
			if (str[i] == 80 && p == 1)
				str[i] = '0';
			if (str[i] == 80)
				p++;
			i++;
		}
	}
	return (str);
}

int	chests_true(t_param *param)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (param->matrix[i])
	{
		j = 0;
		while (param->matrix[i][j])
		{
			if (param->matrix[i][j] == 'C')
				c = 1;
			j++;
		}
		i++;
	}
	return (c);
}
