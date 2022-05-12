/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:43:30 by anfreire          #+#    #+#             */
/*   Updated: 2022/05/12 11:56:49 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_win(t_param *param)
{
	mlx_destroy_window(param->mlx.mlx, param->mlx.win);
	exit (0);
	return (0);
}

int	exit_true(t_param	*param)
{
	int	i;
	int	j;
	int	b00l;

	i = 0;
	b00l = 0;
	while (param->matrix[i])
	{
		j = 0;
		while (param->matrix[i][j])
		{
			if (param->matrix[i][j] == 'E')
				b00l = 1;
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

	if (ac < 1)
	{
		ft_printf("%s\nYou didn't enter any map!", DEFAULT_ERROR);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	param.matrix = heigh_calc(fd, &param);
	get_init(&param);
	param.mlx.mlx = mlx_init();
	param.mlx.win = mlx_new_window(param.mlx.mlx, (param.mlx.lenght * 64),
			(param.mlx.height * 64), "mlx_project");
	put_img_mlx(&param);
	setting_img(&param, (-1), (-1));
	mlx_hook(param.mlx.win, 17, 0, close_win, &param);
	mlx_hook(param.mlx.win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(param.mlx.mlx);
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
